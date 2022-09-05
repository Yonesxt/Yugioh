#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Estructura;

class Escena {
public:
	Escena();
	virtual void Draw(RenderWindow &w)=0;
	virtual void Cambio(Estructura &e, RenderWindow &w)=0;
	virtual ~Escena(){};
private:
};

#endif

