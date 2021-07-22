#include "Filtro.h"
Filtro::Filtro():prezzo(0), tempo(0){}
Filtro::Filtro(int p, int t):prezzo(p), tempo(t){}

int Filtro::getPrezzo(){
	return prezzo;
}

int Filtro::getTempo(){
	return tempo;
}

Filtro::~Filtro(){}

FiltroSeppia::FiltroSeppia():Filtro(2,2){}
FiltroSeppia::~FiltroSeppia(){}

FiltroBellezza::FiltroBellezza():Filtro(4,4){}
FiltroBellezza::~FiltroBellezza(){}


