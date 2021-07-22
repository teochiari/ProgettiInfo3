#include "CartaFotografica.h"
#include "CartaUsata.h"
#include "Usata.h"
#include <vector>
#include <memory>


class CabinaFotografica{
private:

public:
	CabinaFotografica();
	std::vector<FotoSingola> fotoSingola;
	std::vector<QuattroFoto> quattroFoto;
	std::vector<SeiFoto> seiFoto;
	std::vector<TimelapseFoto> timelapseFoto;
	std::vector<std::shared_ptr<CartaUsata>> cartaUsata; ///
	int tempo = 0;
	int credito = 0;

	static CabinaFotografica* creaCabinaFotografica();
	void togliCredito(int c);//
	int controllaCredito(CartaFotografica);//
	void aggiungiCarta(FotoSingola c);//
	void aggiungiCarta(QuattroFoto c);//
	void aggiungiCarta(SeiFoto c);//
	void aggiungiCarta(TimelapseFoto c);//

	template <typename T>
	void aggTempoTogliCredito(T t, T c){
		tempo += t;
		credito= credito - c;
	};

	void stampaSelezione(int codice);//
	void stampaDisponibilitaCarta();//
	void ricaricaCarta(int n);//
	void greetings();//
	void aggiungiCredito(int credito);//
	void aggiungiTempo(int tempo);//
	void stampaCredito();//
	void stampaTempo();//
	void stampaInserisciCredito();//
	void chiediFiltro();//
	void buttaCartaUtilizzata(CartaFotografica c);//
	void stampaCartaUsata();
	void svuotaCartaUsata();

	void show();//
	virtual ~CabinaFotografica();
};
