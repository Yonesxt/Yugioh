#ifndef NOMBRES_H
#define NOMBRES_H
#include <string>
#include "Estructura.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;

class Nombres {
public:
	Nombres();
	string Abecedario(Estructura &e, int t);
private:
	string nombre="", aux="";
	Texture ven;
	Sprite veno;
};

#endif

