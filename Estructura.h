#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include "juego.h"
#include "VentanaPrincipal.h"
#include "Menú.h"
#include "VerCartas.h"
#include "Player.h"

class Estructura {
public:
	Estructura();
	void Arranca();
	void Dibujar();
	void Cambio();
	void CambioEscena(Escena *ne);
	Juego J(){return j;};
	void MostrarGanador();
private:
	Juego j;
	RenderWindow w;
	Event e;
	Escena *escena, *sig_escena=nullptr;
	Texture ven2;
	Sprite veno2;
};

#endif

