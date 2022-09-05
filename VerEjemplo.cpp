#include "VerEjemplo.h"
#include <SFML/Graphics/Sprite.hpp>
#include "Menú.h"

VerEjemplo::VerEjemplo() {
	Atras_textu.loadFromFile("Atras.png");
	Atras.setTexture(Atras_textu);
	Adelante_textu.loadFromFile("Adelante.png");
	Adelante.setTexture(Adelante_textu);
	Atras.setPosition(865, 255);
	Adelante.setPosition(865, 320);
	ViendoEj_textu.loadFromFile("Ej1.png");
	ViendoEj.setTexture(ViendoEj_textu);
	Volver_textu.loadFromFile("Atras.png");
	Volver.setTexture(Volver_textu);
	Volver.setPosition(1, 50);
	Atras.setScale(0.15,0.15);
	Volver.setScale(0.10,0.10);
	Adelante.setScale(0.15,0.15);
}

void VerEjemplo::Draw(RenderWindow &w){
	w.draw(ViendoEj);
	w.draw(Atras);
	w.draw(Adelante);
	w.draw(Volver);
	if(Adelante.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		while(Adelante.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
		if(i<14)
		{
			i++;
			nn<<i;
			n="Ej";n+=nn.str();n+=".png";
			ViendoEj_textu.loadFromFile(n);
			nn.str(std::string());
		}
		else if(i>=14 )
		{
			ViendoEj_textu.loadFromFile("ej1.png");
			i=1;
		}
	}
	if(Atras.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		while(Atras.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
		if(i>1)
		{
			i--;
			nn<<i;
			n="Ej";n+=nn.str();n+=".png";
			ViendoEj_textu.loadFromFile(n);
			nn.str(std::string());
		}
		else if(i<=1)
		{
			ViendoEj_textu.loadFromFile("ej14.png");
			i=14;
		}
	}
	
	w.display();
	
}

void VerEjemplo::Cambio(Estructura &e, RenderWindow &w){
	if(Volver.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		e.CambioEscena(new Menu());
}


