#include <iostream>
using namespace std;
#include "CabinaFotografica.h"

int main() {
	CabinaFotografica* cabina = CabinaFotografica::creaCabinaFotografica();
	cabina->show();
	return 0;
}
