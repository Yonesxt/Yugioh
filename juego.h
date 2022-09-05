#ifndef JUEGO_H
#define JUEGO_H
#include "Player.h"

class Juego {
public:
	Juego(string a, string b);
	void CambNom(string n, int p){
		if(p==1)
			p1.CambNom(n);
		else
			p2.CambNom(n);
	};
	Player* VerJugador(int a){if(a==1)return &p1; else return &p2;};
	int EleccionTurno(int c);
	void Atacar (int i1, int i2, int random);
	int Efecto(int c, int at1, int at2);
	int Cont(){return cont;};
	string VerGanador();
	bool Finalizado();
	void ActualizarPlayer(Player aux1, Player aux2)
	{
		p1=aux1;
		p2=aux2;
	}
private:
		Player p1, p2;
		int random, cont;
};

#endif

