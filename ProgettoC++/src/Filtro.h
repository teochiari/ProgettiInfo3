class Filtro {
private:
	int prezzo;
	int tempo;
public:
	Filtro();
	Filtro(int p, int t);
	int getPrezzo();
	int getTempo();
	virtual ~Filtro();
};

class FiltroSeppia:public Filtro{
public:
	FiltroSeppia();
	virtual  ~FiltroSeppia();
};

class FiltroBellezza:public Filtro{
public:
	FiltroBellezza();
	virtual  ~FiltroBellezza();
};

