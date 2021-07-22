asm Distributore

import StandardLibrary

signature:
	domain CreditoList subsetof Integer
	domain FotoList subsetof String
	enum domain State = {START | INSERIRECREDITO | CONTROLLACREDITO | INSERIRETIPOFOTO | CONTROLLATIPOFOTO |  INSERIREFILTRO | CONTROLLAFILTRO | AGGIUNGIDUECOPIE | CONTROLLADUECOPIE}
	dynamic controlled credito: Integer
	dynamic controlled fotografia:String
	dynamic controlled currentState: State
	dynamic controlled messaggio: String
	dynamic controlled filtro: Integer
	dynamic controlled dueCopie:Integer
	
	
	dynamic monitored inputText: String
	dynamic monitored inputInt: Integer
	
	static isValidCredito: Integer -> Boolean
	static isValidFoto: String -> Boolean
	static isAcceptable: Integer -> Boolean
	static isAcceptableDueCopie: Integer -> Boolean
	

definitions:
	domain CreditoList = {1, 2}
	domain FotoList = {"Singola", "Timelapse"}
	function isValidCredito($credito in Integer) = 
		if(exist $u in CreditoList with $u = $credito) then
			true
		else
			false
		endif
	
	function isValidFoto($foto in String) = 
		if(exist $f in FotoList with $f = $foto) then
			true
		else
			false
		endif
		
	function isAcceptable($filtro in Integer) = 
		if($filtro<=1 and $filtro>=0) then
			true
		else
			false
		endif
		
	function isAcceptableDueCopie($latte in Integer) = 
		if($latte=1) then
			true
		else
			false
		endif
		
	macro rule r_inserireCredito = 
		if(currentState = INSERIRECREDITO) then
			par
				credito:= inputInt
				currentState:= CONTROLLACREDITO
			endpar
		endif
		
	macro rule r_controllaCredito = 
		if(currentState = CONTROLLACREDITO) then
			if(isValidCredito(credito)) then
				par
					currentState:=INSERIRETIPOFOTO
					messaggio:="Inserire il tipo di foto(Singola/Timelapse)"
				endpar
			else
				par
					currentState:=START
					messaggio:="Credito scorretto"
				endpar
			endif
		endif
		
		macro rule r_inserireTipoFoto = 
			if(currentState = INSERIRETIPOFOTO) then
				par
					fotografia:= inputText
					currentState:= CONTROLLATIPOFOTO
				endpar
			endif
			
		macro rule r_controllaTipoFoto = 
			if(currentState = CONTROLLATIPOFOTO) then
				if(isValidFoto(fotografia)) then
					par
						currentState:=INSERIREFILTRO
						messaggio:="Inserire la cifra del filtro: 0->Bellezza 1->Seppia"
					endpar
				else
					par
						currentState:=INSERIRETIPOFOTO
						messaggio:="Tipo foto scorretto"
					endpar
				endif
			endif
		
		macro rule r_inserireFiltro = 
			if(currentState = INSERIREFILTRO) then
				par
					filtro:= inputInt
					currentState:= CONTROLLAFILTRO
				endpar
			endif
			
		macro rule r_controllaFiltro= 
			if(currentState = CONTROLLAFILTRO) then
				if(isAcceptable(filtro)) then
					par
						currentState:= AGGIUNGIDUECOPIE
						messaggio:="Vuoi due copie? 1 si altrimenti no"
					endpar
				else
					par
						currentState:=INSERIREFILTRO
						messaggio:="Numero filtro scorretto"
					endpar
				endif
			endif
			
			macro rule r_inserireDueCopie =
				if(currentState = AGGIUNGIDUECOPIE ) then
					par
						dueCopie:=inputInt
						currentState:=CONTROLLADUECOPIE
					endpar
				endif
				
			macro rule r_controllaDueCopie = 
				if(currentState = CONTROLLADUECOPIE) then
					if(isAcceptableDueCopie(dueCopie)) then
						par
							currentState:=START
							messaggio:="Stampa in due copie"
						endpar
					else
						par
							currentState:=START
							messaggio:="Stampa in una copia"
						endpar
					endif
				endif
				
			main rule r_Main = 
				if(currentState = START) then
					par
						currentState := INSERIRECREDITO
						messaggio:="Inserire credito (1 o 2)"
					endpar
				else
					par
					r_inserireCredito[]
					r_controllaCredito[]
					r_inserireTipoFoto[]
					r_controllaTipoFoto[]
					r_inserireFiltro[]
					r_controllaFiltro[]
					r_inserireDueCopie[]
					r_controllaDueCopie[]
					endpar
				endif
				

// INITIAL STATE
default init s0:
	function currentState = START
	function inputText = ""
	function inputInt = 0
