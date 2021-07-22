#include "CabinaFotografica.h"
#import "CartaFotografica.h"
//#include "CartaUsata.h"
#include "Usata.h"
#include <iostream>
#include <string>

using namespace std;
static bool inizializzato = false;
static CabinaFotografica* cabina;


CabinaFotografica* CabinaFotografica::creaCabinaFotografica(){
	if(!inizializzato){
		cabina = new CabinaFotografica();
		inizializzato = true;
	}
	return cabina;
}
CabinaFotografica::CabinaFotografica(){}


int CabinaFotografica::controllaCredito(CartaFotografica carta){
	if(credito<carta.getPrezzo()){
			cout << "Non hai abbastanza credito, aggiungine altro premendo 7" << endl;
			return 0;
		}
	return 1;
}

void CabinaFotografica::aggiungiTempo(int t){
	tempo+=t;
}
void CabinaFotografica::aggiungiCredito(int c){
	credito+=c;
}
void CabinaFotografica::togliCredito(int c){
	credito=credito-c;
}
void CabinaFotografica::stampaCredito(){
	cout << "Credito: " << credito << endl;
}
void CabinaFotografica::stampaTempo(){
	cout << "Tempo: " << tempo << endl;
}
void CabinaFotografica::stampaInserisciCredito(){
	string inputCreditoTmp;
	int inputCredito = 0;
	cout << "Quanto credito vuoi aggiungere?[Solo numeri] " << tempo << endl;
	cin>>inputCreditoTmp;
	if(inputCreditoTmp!="") inputCredito = stoi(inputCreditoTmp);
	aggiungiCredito(inputCredito);
}

void CabinaFotografica::aggiungiCarta(FotoSingola f){
	fotoSingola.push_back(f);
}
void CabinaFotografica::aggiungiCarta(QuattroFoto f){
	quattroFoto.push_back(f);
}
void CabinaFotografica::aggiungiCarta(SeiFoto f){
	seiFoto.push_back(f);
}
void CabinaFotografica::aggiungiCarta(TimelapseFoto f){
	timelapseFoto.push_back(f);
}
void CabinaFotografica::chiediFiltro(){
	FiltroSeppia fs = FiltroSeppia();
	FiltroBellezza fb = FiltroBellezza();
	string tmpCodice;
	int codice;
	cout << "Quale filtro vuoi applicare" << endl;
	cout << "1:Filtro Seppia - Costo:"<< fs.getPrezzo()<<" - Tempo: "<<fs.getTempo()<<endl;
	cout << "2:Filtro Bellezza - Costo:"<< fb.getPrezzo()<<" - Tempo: "<<fb.getTempo()<<endl;
	cout << "3:Nessun Filtro - Costo: 0 - Tempo: 0"<<endl;

	cin>>tmpCodice;
	if(tmpCodice!="") codice = stoi(tmpCodice);
	//cout << "Codice premuto: " << codice << endl;
	if(codice == 1) {
		aggiungiTempo(fs.getTempo());
		togliCredito(fs.getPrezzo());
	}
	if(codice == 2) {
		aggiungiTempo(fb.getTempo());
		togliCredito(fb.getPrezzo());
	}
	else if(codice == 3) return;
	if(codice<1 || codice >3) return;

}
void CabinaFotografica::buttaCartaUtilizzata(CartaFotografica c){
	CartaUsata cu = CartaUsata(c, tempo) ;
	cartaUsata.push_back(shared_ptr<CartaUsata>(new CartaUsata(c,tempo)));
}
void CabinaFotografica::stampaCartaUsata(){
	for(int i=0; i<cartaUsata.size(); i++){
		cout<<"Carta usata Tempo utilizzo: "<<cartaUsata[i].get()->tempoUtilizzo<<endl;
	}
	if(cartaUsata.size()==0) cout<<"Carta Usata Vuota" <<endl;
}

void CabinaFotografica::svuotaCartaUsata(){
	if(cartaUsata.size()==0) {cout<<"Nessuna carta da svuotare"<<endl;}
	int dim = cartaUsata.size();
	for(int i=0; i<dim; i++){
		cartaUsata.pop_back();
	}
	cout<<"Carta eliminata, dim cartaUsata: "<<cartaUsata.size()<<endl;
}

void CabinaFotografica::stampaSelezione(int codice){
	CartaFotografica carta;
	if(codice==1){
		if(fotoSingola.size()==0){
			cout << "Prodotto Esaurito" << endl; return;
		}
		else {
			carta = fotoSingola.back();
			if(controllaCredito(carta)==1){
				fotoSingola.pop_back();
				chiediFiltro();
				aggTempoTogliCredito(carta.getTempo(), carta.getPrezzo());
				//aggiungiTempo(carta.getTempo());
				//togliCredito(carta.getPrezzo());
				buttaCartaUtilizzata(carta);
				cout << "Erogazione Prodotto" << endl;
			}

		}

	}
	if(codice==2){
			if(quattroFoto.size()==0){
				cout << "Prodotto Esaurito" << endl;
				 return;
			}
			else {
				carta=quattroFoto.back();
				if(controllaCredito(carta)==1){
					quattroFoto.pop_back();
					chiediFiltro();
					aggiungiTempo(carta.getTempo());
					togliCredito(carta.getPrezzo());
					buttaCartaUtilizzata(carta);
					cout << "Erogazione Prodotto" << endl;
				}
			}
		}
	if(codice==3){
			if(seiFoto.size()==0){
				cout << "Prodotto Esaurito" << endl;
				 return;
			}
			else {
				carta=seiFoto.back();
				if(controllaCredito(carta)==1){
					seiFoto.pop_back();
					chiediFiltro();
					aggiungiTempo(carta.getTempo());
					togliCredito(carta.getPrezzo());
					buttaCartaUtilizzata(carta);
					cout << "Erogazione Prodotto" << endl;
				}
			}
		}
	if(codice==4){
			if(timelapseFoto.size()==0) {
				cout << "Prodotto Esaurito" << endl;
				 return;
			}
			else {
				carta=timelapseFoto.back();
				if(controllaCredito(carta)==1){
					timelapseFoto.pop_back();
					chiediFiltro();
					aggiungiTempo(carta.getTempo());
					togliCredito(carta.getPrezzo());
					buttaCartaUtilizzata(carta);
					cout << "Erogazione Prodotto" << endl;
				}
			}
		}

}

void CabinaFotografica::stampaDisponibilitaCarta(){
	cout << "Disponibilità:" << endl;
	cout << "Singola  4__Foto  6__Foto  Timelapse" <<endl;
	cout << fotoSingola.size() <<"        "<< quattroFoto.size() <<"        "<< seiFoto.size() <<"        "<< timelapseFoto.size() << endl;
}
void CabinaFotografica::ricaricaCarta(int n){
	FotoSingola fs = FotoSingola();
	QuattroFoto qf = QuattroFoto();
	SeiFoto sf = SeiFoto();
	TimelapseFoto tf = TimelapseFoto();

	fotoSingola.push_back(fs);
	quattroFoto.push_back(qf);
	seiFoto.push_back(sf);
	timelapseFoto.push_back(tf);
}
void CabinaFotografica::greetings(){
	//cout <<"dim pre svuotamento "<<cartaUsata.size()<<endl;
	cout << "Tempo di utilizzo: " << tempo << endl;
	svuotaCartaUsata();
	//stampaCartaUsata();
	cout << "Uscita dalla cabina, grazie" << endl;
}

CabinaFotografica::~CabinaFotografica(){

	delete cabina;
}

void CabinaFotografica::show(){

	int cabinaOpen = 1;
	int codice;
	string tmpCodice;
	ricaricaCarta(1);
	while(cabinaOpen==1){
		cout << "Quale tipo di fortografia desideri? (Inserire il codice relativo)" << endl;
		cout << "1:  Foto Singola" << endl;
		cout << "2:  4 Foto" << endl;
		cout << "3:  6 Foto" << endl;
		cout << "4:  Timelapse Foto" << endl;
		cout << "6:  Stampa Carta Usata" << endl;
		cout << "7:  Inserisci Credito" << endl;
		cout << "8:  Ricarica Carta" << endl;
		cout << "9:  Esci dalla Cabina" << endl;
		stampaDisponibilitaCarta();
		stampaTempo();
		stampaCredito();
		cin>>tmpCodice;
		if(tmpCodice!="") codice = stoi(tmpCodice);
		//cout << "Codice premuto: " << codice << endl;
		if(codice ==8) ricaricaCarta(1);
		if(codice ==7) stampaInserisciCredito();
		else if(codice==9) cabinaOpen=0;
		else if(codice<=4 && codice>=1) stampaSelezione(codice);
		if(codice==6) stampaCartaUsata();

	};
	greetings();
}
