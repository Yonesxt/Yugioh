#include "VerCartas.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Menú.h"

VerCartas::VerCartas():bin("Cartas.dat", ios::binary|ios::in) 
{
	tablerocard_textu.loadFromFile("Tablero_cartas.png");	
	tablerocard.setTexture(tablerocard_textu);
	atras_textu.loadFromFile("Atras.png");
	atras.setTexture(atras_textu);
	atras.setScale(0.15,0.15);
	atras.setPosition(10,10);
	
	bin.seekg(0);
	for(size_t i=0;i<36;i++)
	{
		bin.read(reinterpret_cast<char*>(&c),sizeof(c));
		bin.read(reinterpret_cast<char*>(&f),sizeof(f));
		efe.push_back(f);
		card.push_back(c);
	}
	
	for(int i=0;i<efe.size();i++)
	{
		string a;
		a.resize(155,32);
		a.replace(0,efe[i].length(),efe[i]);
		s1.push_back(a.substr(0,25));
		s2.push_back(a.substr(25,25));
		s3.push_back(a.substr(50,25));
		s4.push_back(a.substr(75,25));
		s5.push_back(a.substr(100,25));	
		s6.push_back(a.substr(125,25));	
	}
}

void VerCartas::Draw(RenderWindow &w)
{
	w.draw(tablerocard);
	w.draw(atras);
	
	for(size_t i=0;i<card.size();i++) 
	{  
		nadita.loadFromFile("Nada.png");
		ca.setTexture(nadita);
		string s=card[i].img;
		C.loadFromFile(s);
		ca.setTexture(C);
		ca.setScale(0.17,0.17);
		if(i<9)
			ca.setPosition(250+(i*82), 50);
		else if (i<18)
			ca.setPosition(250+((i-9)*82), 175);
		else if (i<27)
			ca.setPosition(250+((i-18)*82), 300);
		else if (i<36)
			ca.setPosition(250+((i-27)*82), 425);
		if(carta.size()<=card.size())
			carta.resize(i+1);
		carta[i]=ca;
		w.draw(carta[i]);	
	}
	for(size_t i=0;i<card.size();i++) 
	{  
		Text descripcion,descripcion2,descripcion3,descripcion4,descripcion5;
		if (!fuente.loadFromFile("arial.ttf"));
		if(a==i && not carta[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
		{
			Dorso.loadFromFile("Dorso.png");
			Cardmos.setScale(1, 1);
			Cardmos.setPosition(2, 74); 
			Cardmos.setTexture(Dorso);
			nadita.loadFromFile("Nada.png");
			Cardmos1.setTexture(nadita);
			Cardmos1.setPosition(2, 74); 
			Cardmos1.setScale(0.475, 0.475);
			a=0;
		}
		if (carta[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
		{
			string s=card[i].img;
			mos.loadFromFile(s);
			Cardmos1.setTexture(mos);
			Cardmos1.setPosition(2, 74); 
			Cardmos1.setScale(0.475, 0.475);
			a=i;
			
			descripcion.setFont(fuente);
			descripcion.setCharacterSize(15);
			descripcion.setPosition(5,370);
			descripcion.setFillColor(sf::Color::Black);
			descripcion.setString(s1[i]);
			w.draw(descripcion);
			descripcion.setPosition(5,390);
			descripcion.setString(s2[i]);
			w.draw(descripcion);
			descripcion.setPosition(5,410);
			descripcion.setString(s3[i]);
			w.draw(descripcion);
			descripcion.setPosition(5,430);
			descripcion.setString(s4[i]);
			w.draw(descripcion);
			descripcion.setPosition(5,450);
			descripcion.setString(s5[i]);
			w.draw(descripcion);
			descripcion.setPosition(5,470);
			descripcion.setString(s6[i]);
			w.draw(descripcion);
		}
		w.draw(Cardmos1);
	}
	w.display();
}


void VerCartas::Cambio(Estructura &e, RenderWindow &w)
{
	if (atras.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w)))&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
		e.CambioEscena(new Menu());
}
