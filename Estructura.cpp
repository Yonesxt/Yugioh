#include "Estructura.h"
using namespace sf;

Estructura::Estructura():j("", ""),  w(VideoMode(1000,625),"YU-GI-OH!")
{
	escena=new Menu(); 
	w.setFramerateLimit(60);
	Image icon;
	icon.loadFromFile("icon.jpg"); 
	w.setIcon(icon.getSize().x,icon.getSize().y, icon.getPixelsPtr()); ///icono
}

void Estructura::Arranca()
{
	while(w.isOpen()) 
	{
		while(w.pollEvent(e))
		{
			if(e.type == Event::Closed)
				w.close();	
		}
		Dibujar();
		Cambio();
		if (sig_escena) 
		{
			delete escena;
			escena = sig_escena;
			sig_escena = nullptr;
		}
	}
}

void Estructura::Dibujar()
{
	escena->Draw(w);
}

void Estructura::Cambio()
{
	escena->Cambio(*this, w);
}

void Estructura::CambioEscena(Escena *ne)
{
	sig_escena=ne;
}
