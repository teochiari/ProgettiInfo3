#include "CartaFotografica.h"
#include <iostream>

CartaFotografica::CartaFotografica(){};
CartaFotografica::CartaFotografica(int p, int t):prezzo(p), tempo(t){};

int CartaFotografica::getPrezzo(){
	return prezzo;
}

int CartaFotografica::getTempo(){
	return tempo;
}

Filtro CartaFotografica::getFiltro(){
	return filtro;
}

void CartaFotografica::setFiltro(Filtro f){
	filtro=f;
}


CartaFotografica::~CartaFotografica(){}

FotoSingola::FotoSingola():CartaFotografica(1,2){}
FotoSingola::~FotoSingola(){}

QuattroFoto::QuattroFoto():CartaFotografica(3,6){}
QuattroFoto::~QuattroFoto(){}

SeiFoto::SeiFoto():CartaFotografica(4,8){}
SeiFoto::~SeiFoto(){}

TimelapseFoto::TimelapseFoto():CartaFotografica(6,12){}
TimelapseFoto::~TimelapseFoto(){}
