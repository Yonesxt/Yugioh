#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Player.h"
#include <vector>
#include "CartasenJuego.h"
using namespace std;

class Player {
public:
	Player(string nom, string a);
	void CambNom(string n){nombre=n;};
	int VerVida(){return vida;};
	int EstrellasCampo();
	string VerNombre(){return nombre;};
	void Invocar(int a);
	void Actual(int i);
	int Juntar(){c.SacardelMazo();};
	void Cementerio(int i);
	void Sacrificar(int i);
	void Cambiar(int i);
	void Imitador(Player &p, int i1, int i2);
	void MasDefensa(int i);
	void MasAtaque(int i, int a);
	void Camicase(Player &p, int i1, int i2);
	void Matansa(Player &p, int i1);
	void Control(Player &p, int i1);
	void Borrar(int i){c.Erase(i);};
	void Ataco(int i);
	void Cambio(int i);
	void Reinicio();
	bool sino(int i){return c.SiNo(i);};
	Carta ElegirRival(Player &p, int i);
	Carta ElegirQuienAtaca(Player &p, int i);
	vector<Carta> VerMano(){return c.VerM();};
	vector<Carta> VerCampo(){return c.VerC();};
	vector<Carta> VerCementerio(){return c.VerCem();};
	Carta Una(int i);
	void Danio(int algo);
	bool EstaVivo();
	bool TieneCartas();
private:
	int vida;
	string nombre;
	CartasenJuego c;
};
#endif


