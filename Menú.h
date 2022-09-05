#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Escena.h"
#include "Estructura.h"
#include <string>
using namespace std;
using namespace sf;

class Menu : public Escena{
public:
	Menu();
	void Draw(RenderWindow &w) override;
	void Cambio(Estructura &e, RenderWindow &w) override;
private:
	Texture intro_textu;
	Sprite intro;
	Texture iniciar_textu;
	Sprite iniciar;
	Texture ganadores_textu;
	Sprite ganadores;
	Texture cartas_textu;	
	Sprite cartas;
	Texture Ejemplo_textu;
	Sprite Ejemplo;
	string n1="", n2="";
};

#endif

