#include "Nombres.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
using namespace sf;

Nombres::Nombres() {
	
}

string Nombres::Abecedario(Estructura &e, int t)
{
	if(t==1)
		nombre="";
	else
		nombre="";
	RenderWindow nom(VideoMode(333, 49),"YU-GI-OH!");
	nom.setFramerateLimit(60);
	
	while(nom.isOpen())
	{	
		nom.requestFocus();
		int aceptar=0, cancelar=0;
		Text texto;
		Font fuente;
		if (!fuente.loadFromFile("arial.ttf"));
		texto.setFont(fuente);
		texto.setCharacterSize(18);
		texto.setFillColor(sf::Color::Black);
		texto.setPosition(80, 13);
		ven.loadFromFile("nombre.jpg");
		veno.setTexture(ven);
		nom.draw(veno);
		if(t==1)
			texto.setString("ingresar nombre: Player Uno");
		else
			texto.setString("ingresar nombre: Player Dos");
		nom.draw(texto);
		nom.display();
		while (not Keyboard::isKeyPressed(Keyboard::Key::Return))
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::A))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::A)){}
				nombre+="A";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::B))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::B)){}
				nombre+="B";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::C))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::C)){}
				nombre+="C";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::D))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::D)){}
				nombre+="D";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::E))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::E)){}
				nombre+="E";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::F))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::F)){}
				nombre+="F";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::G))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::G)){}
				nombre+="G";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::H))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::H)){}
				nombre+="H";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::I))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::I)){}
				nombre+="I";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::J))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::J)){}
				nombre+="J";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::K))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::K)){}
				nombre+="K";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::L))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::L)){}
				nombre+="L";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::M))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::M)){}
				nombre+="M";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::N))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::N)){}
				nombre+="N";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::O))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::O)){}
				nombre+="O";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::P))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::P)){}
				nombre+="P";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Q))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::Q)){}
				nombre+="Q";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::R))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::R)){}
				nombre+="R";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::S))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::S)){}
				nombre+="S";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::T))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::T)){}
				nombre+="T";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::U))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::U)){}
				nombre+="U";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::V))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::V)){}
				nombre+="V";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::W))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::W)){}
				nombre+="W";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::X))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::X)){}
				nombre+="X";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Y))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::Y)){}
				nombre+="Y";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Z))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::Z)){}
				nombre+="Z";
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::BackSpace))
			{
				while(Keyboard::isKeyPressed(Keyboard::Key::BackSpace)){}
				nombre.pop_back();
				texto.setString(nombre);
				nom.draw(veno);
				nom.draw(texto);
				nom.display();
			}
		}
		while (Keyboard::isKeyPressed(Keyboard::Key::Return)){aceptar=1;}
		
		if(aceptar==1)
		{
			ven.loadFromFile("Nada-c.png");
			nom.close();
			return nombre;
		}
	}
}
