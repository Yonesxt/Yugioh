#ifndef VERCARTAS_H
#define VERCARTAS_H
#include <string>
#include "CartasenJuego.h"
#include <fstream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Escena.h"
using namespace std;
using namespace sf;

class VerCartas : public Escena{
public:
	VerCartas();
	void Draw(RenderWindow &w) override;
	void Cambio(Estructura &e, RenderWindow &w) override;
private:
	int a=0;
	char f[1000];
	vector<string> efe, s1, s2, s3, s4, s5, s6;
	vector<Carta> card;
	fstream bin;
	Carta c;
	Texture atras_textu;
	Sprite atras;
	Texture tablerocard_textu;	
	Sprite tablerocard;
	Texture nadita;
	Sprite auxiliar1, auxiliar2, Ca1, Ca2, ca;
	Texture Dorso;
	Texture mos;
	Sprite Cardmos, Cardmos1;
	Texture C;
	vector<Sprite> carta;
	Font fuente;
};

#endif

