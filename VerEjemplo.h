#ifndef VEREJEMPLO_H
#define VEREJEMPLO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Escena.h"
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <sstream>
using namespace std;

class VerEjemplo: public Escena{ 
public:
	VerEjemplo();
	void Draw(RenderWindow &w) override;;
	void Cambio(Estructura &e, RenderWindow &w) override;
private:
	Texture Atras_textu;
	Sprite Atras;
	Texture Adelante_textu;
	Sprite Adelante;
	Texture ViendoEj_textu;
	Sprite ViendoEj;
	int i=2;
	string n;
	stringstream nn;
	Texture Volver_textu;
	Sprite Volver;
};

#endif

