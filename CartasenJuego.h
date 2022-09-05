#ifndef CARTASENJUEGO_H
#define CARTASENJUEGO_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Carta
{
	char monstruo[200], img[200];
	int defensa=0, ataque=0, estrellas=0, efecto=0;
	bool aod=true, ataco=false, cambio=false;
};

class CartasenJuego {
public:
	CartasenJuego(string arch);
	void Bajar(int a);
	void Actu(int i);
	void SacardelMazo();
	void Cem(int i);
	void Sacrificio(int i);
	void Modo(int i);
	void YaAtaco(int i);
	void YaCambio(int i);
	void Imitar(Carta c, int i1);
	void Defensa(int i);
	void Ataque(int i, int a);
	void Erase(int i);
	void Agregar(Carta c){cartacampo.push_back(c);};
	void reinicio();
	bool SiNo(int i){
		if(cartacampo[i].ataco)
			cout<<"SINO = TRUE"<<endl<<endl;
		else
			cout<<"SINO = FALSE"<<endl<<endl;
		return cartacampo[i].ataco;};
		int Mazo(){return mazo.size();};
		vector<Carta> VerM(){return cartamano;};
		vector<Carta> VerC(){return cartacampo;};
		vector<Carta> VerCem(){return cementerio;};
protected:
	vector<Carta> cartamano, cartacampo, cementerio, mazo;
};


#endif

