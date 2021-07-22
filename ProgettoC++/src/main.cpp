//============================================================================
// Name        : ProgettoC++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * membri virtual ------------------------------------------------
 * classi template no ------template function si
 * ereditarietà multipla ok
 * puntatori intelligenti ok
 * costruttori distruttori bho costruttori e distruttori ok
 * campi pub priv ok membri virtual non ?
 * overloading ok overriding  ?
 * stl ok
 */

#include <iostream>
using namespace std;
#include "CabinaFotografica.h"

int main() {
	CabinaFotografica* cabina = CabinaFotografica::creaCabinaFotografica();
	cabina->show();
	return 0;
}
