#include "Menú.h"
#include <SFML/Window/Mouse.hpp>
#include "Estructura.h"
#include "VentanaPrincipal.h"
#include "VerCartas.h"
#include "VerEjemplo.h"
#include "Nombres.h"

Menu::Menu() 
{
	intro_textu.loadFromFile("Start Game.png");
	intro.setTexture(intro_textu);
	iniciar_textu.loadFromFile("Start Game Boton.png");
	iniciar.setTexture(iniciar_textu);
	iniciar.setPosition(375, 250);
	cartas_textu.loadFromFile("Ver Cartas.png");
	cartas.setTexture(cartas_textu);
	cartas.setPosition(375, 450);
	Ejemplo_textu.loadFromFile("Ejemplo.png");
	Ejemplo.setTexture(Ejemplo_textu);
	Ejemplo.setPosition(375, 350);
}

void Menu::Draw(RenderWindow &w)
{
	w.draw(intro);
	w.draw(iniciar);
	w.draw(cartas);
	w.draw(Ejemplo);
	w.display();
}

void Menu::Cambio(Estructura &e, RenderWindow &w)
{
	if(iniciar.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Nombres n;
		while(n1=="")
			n1=n.Abecedario(e, 1);
		while(n2=="")
			n2=n.Abecedario(e, 2);
		e.CambioEscena(new VentanaPrincipal(e.J(), n1, n2));
	}
	else if(cartas.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		e.CambioEscena(new VerCartas());
	else if(Ejemplo.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		e.CambioEscena(new VerEjemplo() );
}
