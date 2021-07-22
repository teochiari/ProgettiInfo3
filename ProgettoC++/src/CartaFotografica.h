#include "Filtro.h"


class CartaFotografica {
private:
	int prezzo;
	int tempo;
	Filtro filtro;
public:
	CartaFotografica();
	CartaFotografica(int p, int n);
	int getPrezzo();
	int getTempo();
	Filtro getFiltro();
	void setFiltro(Filtro f);
	virtual ~CartaFotografica();

};

class FotoSingola:public CartaFotografica{
public:
	FotoSingola();
	virtual ~FotoSingola();
};

class QuattroFoto:public CartaFotografica{
public:
	QuattroFoto();
	virtual ~QuattroFoto();
};

class SeiFoto:public CartaFotografica{
public:
	SeiFoto();
	virtual ~SeiFoto();
};

class TimelapseFoto:public CartaFotografica{
public:
	TimelapseFoto();
	virtual ~TimelapseFoto();
};


