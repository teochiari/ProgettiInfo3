#import "CartaFotografica.h"
#import "Usata.h"

class CartaUsata: virtual public CartaFotografica, public Usata{
public:
	CartaFotografica carta;
	CartaUsata();
	CartaUsata(CartaFotografica c, int t);

};
