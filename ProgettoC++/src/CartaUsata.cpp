#include "CartaUsata.h"

CartaUsata::CartaUsata(){}
CartaUsata::CartaUsata(CartaFotografica c, int t){
	tempoUtilizzo = t;
	CartaFotografica(c.getPrezzo(), c.getTempo());
}
//CartaUsata* CartaUsata::creaCartaUsata(CartaFotografica c, int t){
//	return new CartaUsata(c,t);
//}
