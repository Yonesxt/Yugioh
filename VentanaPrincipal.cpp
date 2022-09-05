#include "VentanaPrincipal.h"
#include "juego.h"
#include <string>
#include <SFML/Window/Keyboard.hpp>
#include "Menú.h"
#include "Estructura.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace std;
using namespace sf;

VentanaPrincipal::VentanaPrincipal(Juego juego, string n1, string n2):j("", ""), p1("", ""), p2("", ""), aux1("", ""), aux2("", "")
{
	j=juego;
	j.CambNom(n1, 1);
	j.CambNom(n2, 2);
	p1=*j.VerJugador(1);
	p2=*j.VerJugador(2);
	jug=j.EleccionTurno(cont);
	if(jug==1)
		p1.Juntar();
	else
		p2.Juntar();
	j.ActualizarPlayer(p1, p2);
	
	m_atk.setFont(fuente);m_def.setFont(fuente);
	m_atk.setCharacterSize(20);m_def.setCharacterSize(20);
	m_atk.setFillColor(sf::Color::Black);
	m_def.setFillColor(sf::Color::Black);
	m_atk.setPosition(2,367);
	m_def.setPosition(95,367);
	
	shape.setRadius(15);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(202,0);
	s.setPosition(0,0);
	t.loadFromFile("Fondo.jpg");
	s.setTexture(t);
	Mazo1.loadFromFile("Mazo.jpg");
	Mazoim1.setPosition( 830, 387);
	Mazoim1.setTexture(Mazo1);
	Mazoim2.setPosition(320,133);
	Mazoim2.setTexture(Mazo1);
	Np.loadFromFile("Np.png");
	Np1.setPosition(20,455);
	Np1.setTexture(Np);
	et.loadFromFile("ET1.png");
	et1.setPosition(20,395);
	et1.setTexture(et);
	
	if(!fuente_vida.loadFromFile("Madjoe.ttf"));
	v1=p1.VerVida();
	v2=p2.VerVida();
	holi1<<v1;
	holi2<<v2;
	vida1=holi1.str();
	vida2=holi2.str();
	viviendo1.setFont(fuente_vida);
	viviendo1.setCharacterSize(40);
	viviendo1.setFillColor(sf::Color::Yellow);
	viviendo1.setPosition(70, 540);
	viviendo2.setFont(fuente_vida);
	viviendo2.setCharacterSize(40);
	viviendo2.setFillColor(sf::Color::Yellow);
	viviendo2.setPosition(70, 13);
	
	nombre1.setFont(fuente_vida);
	nombre1.setCharacterSize(40);
	nombre1.setFillColor(sf::Color::Yellow);
	nombre1.setPosition(220, 540);
	nombre2.setFont(fuente_vida);
	nombre2.setCharacterSize(40);
	nombre2.setFillColor(sf::Color::Yellow);
	nombre2.setPosition(220, 13);
}

int VentanaPrincipal::Tabla(int jug)
{
	Player p=*j.VerJugador(jug);
	int m1, m2, ca1, ca2, ce1, ce2;
	cout<<"JUGADOR ---> "<<p.VerNombre()<<endl<<endl;
	cout<<"VIDA ---> "<<p.VerVida()<<endl<<endl;
	vector<Carta> mano=p.VerMano(), campo=p.VerCampo(), cementerio=p.VerCementerio();
	cout<<"Cartas en Mano: "<<endl;
	for(size_t j=0; j<mano.size(); j++)
	{
		cout<<"- "<<j+1<<" monstruo: "<<mano[j].monstruo<<" estrellas: "<<mano[j].estrellas<<endl;
		cout<<"  ataque: "<<mano[j].ataque<<" defensa: "<<mano[j].defensa<<" modo: ";
		if(mano[j].monstruo=="0")
		cout<<"0"<<endl;
		else if(mano[j].aod)
			cout<<"ataque"<<endl;
		else
			cout<<"defensa"<<endl;
		switch(mano[j].efecto)
		{
		case 0:
			cout<<"Sin Efecto"<<endl<<endl;
			break;
		case 1:
			cout<<"Imita ataque y defensa de una carta enemiga"<<endl<<endl;
			break;
		case 2:
			cout<<"Aumenta su defensa 500 y de cambia a modo defensa automaticamente"<<endl<<endl;
			break;
		case 3:
			cout<<"se autodestruye junto a cualquiera del campo adversario"<<endl<<endl;
			break;
		case 4:
			cout<<"sacrifica la vida de sus cartas o las del enemigo según cara o cruz"<<endl<<endl;
			break;
		case 5:
			cout<<"controla un monstruo"<<endl<<endl;
			break;
		case 6:
			cout<<"no la puede atacar al menos que sea la única del campo"<<endl<<endl;
			break;
		case 7:
			cout<<"si es destruida se roba dos cartas del mazo"<<endl<<endl;
			break;
		case 8:
			cout<<"se sacrifica a cambio de la invocacion del dragon de ojos rojos si se tiene a este en la mano"<<endl<<endl;
			break;
		case 9:
			cout<<"al atacar cambia a modo defensa"<<endl<<endl;
			break;
		case 10:
			cout<<"si es destruida destruye al atacante y no se calcula daño"<<endl<<endl;
			break;
		case 11:
			cout<<"al atacar a una que esta en defensa se calcula igualmente el daño y esta cambia a modo defensa"<<endl<<endl;
			break;
		}
	}
	cout<<endl;
	cout<<"Cartas en Campo: "<<endl;
	for(size_t j=0; j<campo.size(); j++)
	{
		cout<<"- "<<j+1<<" monstruo: "<<campo[j].monstruo<<" estrellas: "<<campo[j].estrellas<<endl;
		cout<<"  ataque: "<<campo[j].ataque<<" defensa: "<<campo[j].defensa<<" modo: ";
		if(campo[j].monstruo=="0")
			cout<<"0"<<endl;
		else if(campo[j].aod)
			cout<<"ataque";
		else
			cout<<"defensa";
		cout<<"         ¿CAMBIO? ";
		if(campo[j].cambio)
			cout<<"SI cambio"<<endl;
		else
			cout<<"NO cambio"<<endl;
		switch(campo[j].efecto)
		{
		case 0:
			cout<<"Sin Efecto"<<endl<<endl;
			break;
		case 1:
			cout<<"Imita ataque y defensa de una carta enemiga"<<endl<<endl;
			break;
		case 2:
			cout<<"Aumenta su defensa 500 y de cambia a modo defensa automaticamente"<<endl<<endl;
			break;
		case 3:
			cout<<"se autodestruye junto a cualquiera del campo adversario"<<endl<<endl;
			break;
		case 4:
			cout<<"sacrifica la vida de sus cartas o las del enemigo según cara o cruz"<<endl<<endl;
			break;
		case 5:
			cout<<"controla un monstruo"<<endl<<endl;
			break;
		case 6:
			cout<<"no la puede atacar al menos que sea la única del campo"<<endl<<endl;
			break;
		case 7:
			cout<<"si es destruida se roba dos cartas del mazo"<<endl<<endl;
			break;
		case 8:
			cout<<"se sacrifica a cambio de la invocacion del dragon de ojos rojos si se tiene a este en la mano"<<endl<<endl;
			break;
		case 9:
			cout<<"al atacar cambia a modo defensa"<<endl<<endl;
			break;
		case 10:
			cout<<"si es destruida destruye al atacante y no se calcula daño"<<endl<<endl;
			break;
		case 11:
			cout<<"al atacar a una que esta en defensa se calcula igualmente el daño y esta cambia a modo defensa"<<endl<<endl;
			break;
		}
	}
	cout<<endl;
	cout<<"Cartas en Cementerio: "<<endl;
	for(size_t j=0; j<cementerio.size(); j++)
	{
		cout<<"- "<<j+1<<" monstruo: "<<cementerio[j].monstruo<<" estrellas: "<<cementerio[j].estrellas<<endl;
		cout<<"  ataque: "<<cementerio[j].ataque<<" defensa: "<<cementerio[j].defensa<<" modo: ";
		if(cementerio[j].monstruo=="0")
			cout<<"0"<<endl;
		else if(cementerio[j].aod)
			cout<<"ataque"<<endl;
		else
			cout<<"defensa"<<endl;
		switch(cementerio[j].efecto)
		{
		case 0:
			cout<<"Sin Efecto"<<endl<<endl;
			break;
		case 1:
			cout<<"Imita ataque y defensa de una carta enemiga"<<endl<<endl;
			break;
		case 2:
			cout<<"Aumenta su defensa 500 y de cambia a modo defensa automaticamente"<<endl<<endl;
			break;
		case 3:
			cout<<"se autodestruye junto a cualquiera del campo adversario"<<endl<<endl;
			break;
		case 4:
			cout<<"sacrifica la vida de sus cartas o las del enemigo según cara o cruz"<<endl<<endl;
			break;
		case 5:
			cout<<"controla un monstruo"<<endl<<endl;
			break;
		case 6:
			cout<<"no la puede atacar al menos que sea la única del campo"<<endl<<endl;
			break;
		case 7:
			cout<<"si es destruida se roba dos cartas del mazo"<<endl<<endl;
			break;
		case 8:
			cout<<"se sacrifica a cambio de la invocacion del dragon de ojos rojos si se tiene a este en la mano"<<endl<<endl;
			break;
		case 9:
			cout<<"al atacar cambia a modo defensa"<<endl<<endl;
			break;
		case 10:
			cout<<"si es destruida destruye al atacante y no se calcula daño"<<endl<<endl;
			break;
		case 11:
			cout<<"al atacar a una que esta en defensa se calcula igualmente el daño y esta cambia a modo defensa"<<endl<<endl;
			break;
		}
	}
	cout<<endl;
	return campo.size()+cementerio.size()*10; 
}

void VentanaPrincipal::Draw(RenderWindow &w)
{
	w.draw(s);
	w.draw(Np1);
	w.draw(Mazoim1);
	w.draw(Mazoim2);
	w.draw(Cardmos);
	w.draw(Cardmos1);
	w.draw(Cardmos2);
	
	w.draw(Cardmos3);
	w.draw(et1);
	for(int i=0;i<p1.VerMano().size();i++) 
	{
		if(M1.size()<=p1.VerMano().size())
			M1.resize(i+1);
		else if(M1.size()!=p1.VerMano().size())
			M1.resize(p1.VerMano().size());
		Dorso.loadFromFile("Dorso.png");
		M1[i].setTexture(Dorso);
		M1[i].setScale(0.25,0.25);
	}
	for(int i=0;i<p2.VerMano().size();i++) 
	{
		if(M2.size()<p2.VerMano().size())
			M2.resize(i+1);
		else if(M2.size()!=p2.VerMano().size())
			M2.resize(p2.VerMano().size());
		Dorso.loadFromFile("Dorso.png");
		M2[i].setTexture(Dorso);
		M2[i].setScale(0.25,0.25);
	}
	if(jug==1)
	{
		for(size_t j=0;j<p1.VerMano().size();j++)
		{
			nadita.loadFromFile("Nada.png");
			auxiliar1.setTexture(nadita);
			string s1=p1.VerMano()[j].img;
			Card1.loadFromFile(s1);
			auxiliar1.setTexture(Card1);
			auxiliar1.setScale(0.12,0.12);
			if(j<5)
				auxiliar1.setPosition(417+(j*82), 394);
			else
				auxiliar1.setPosition(458+((j-4)*82), 487.2);
			if(Mano1.size()<=p1.VerMano().size())
				Mano1.resize(j+1);
			else if(Mano1.size()!=p1.VerMano().size())
				Mano1.resize(p1.VerMano().size());
			Mano1[j]=auxiliar1;
			w.draw(Mano1[j]);
		}
		for(size_t j=0;j<p2.VerMano().size();j++)
		{
			nadita.loadFromFile("Nada.png");
			auxiliar2.setTexture(nadita);
			auxiliar2.setScale(0.12,0.12);
			if(j<5)
			{
				auxiliar2.setPosition(417+(j*82), 148);
				M2[j].setPosition(417+(j*82), 148);
			}
			else
			{
				auxiliar2.setPosition(458+((j-4)*82), 54.8);
				M2[j].setPosition(458+((j-4)*82), 54.8);
			}
			if(Mano2.size()<=p2.VerMano().size())
			   Mano2.resize(j+1);
			else if(Mano2.size()!=p2.VerMano().size())
				Mano2.resize(p2.VerMano().size());
			Mano2[j]=auxiliar2;
			w.draw(M2[j]);
			w.draw(Mano2[j]);
		}
	}
	else 
	{
		for(size_t j=0;j<p2.VerMano().size();j++)
		{
			nadita.loadFromFile("Nada.png");
			auxiliar2.setTexture(nadita);
			string s2=p2.VerMano()[j].img;
			Card2.loadFromFile(s2);
			auxiliar2.setTexture(Card2);
			auxiliar2.setScale(0.12,0.12);
			if(j<5)
				auxiliar2.setPosition(417+(j*82), 148);
			else
				auxiliar2.setPosition(458+((j-4)*82), 54.8);
			if(Mano2.size()<=p2.VerMano().size())
				Mano2.resize(j+1);
			else if(Mano2.size()!=p2.VerMano().size())
				Mano2.resize(p2.VerMano().size());
			Mano2[j]=auxiliar2;
			w.draw(Mano2[j]);
		}
		for(size_t j=0;j<p1.VerMano().size();j++)
		{
			nadita.loadFromFile("Nada.png");
			auxiliar1.setTexture(nadita);
			auxiliar1.setScale(0.12,0.12);
			if(j<5)
			{
				auxiliar1.setPosition(417+(j*82), 394);
				M1[j].setPosition(417+(j*82), 394);
			}
			else
			{
				auxiliar1.setPosition(458+((j-4)*82), 487.2);
				M1[j].setPosition(458+((j-4)*82), 487.2);
			}
			if(Mano1.size()<=p1.VerMano().size())
			   Mano1.resize(j+1);
			else if(Mano1.size()!=p1.VerMano().size())
				Mano1.resize(p1.VerMano().size());
			Mano1[j]=auxiliar1;
			w.draw(M1[j]);
			w.draw(Mano1[j]);
		}
	}
	for(int j=0;j<p1.VerCampo().size();j++)
	{
		string s1=p1.VerCampo()[j].img;
		Card1.loadFromFile(s1);
		Ca1.setTexture(Card1);
		Ca1.setScale(0.12,0.12);
		if(p1.VerCampo()[j].aod)
		{
			Ca1.setRotation(0.f);
			Ca1.setPosition(413+(j*83), 314);
		}
		else
		{
			Ca1.setRotation(90.f);
			Ca1.setPosition(475+(j*83), 325.5);
		}
		if(Campo1.size()<=p1.VerCampo().size())
					   Campo1.resize(j+1);
		else if(Campo1.size()!=p1.VerCampo().size())
			Campo1.resize(p1.VerCampo().size());
		Campo1[j]=Ca1;
		w.draw(Campo1[j]);
	}
	for(int j=0;j<p2.VerCampo().size();j++)
	{
		string s2=p2.VerCampo()[j].img;
		Card2.loadFromFile(s2);
		Ca2.setTexture(Card2);
		Ca2.setScale(0.12,0.12);
		if(p2.VerCampo()[j].aod)
		{
			Ca2.setRotation(0.f);
			Ca2.setPosition(413+(j*83), 230);
		}
		else
		{
			Ca2.setRotation(90.f);
			Ca2.setPosition(475+(j*83), 241.5);
		}
		if(Campo2.size()<=p2.VerCampo().size())
					   Campo2.resize(j+1);
		else if(Campo2.size()!=p2.VerCampo().size())
			Campo2.resize(p2.VerCampo().size());
		Campo2[j]=Ca2;
		w.draw(Campo2[j]);
	}
	viviendo1.setString(vida1);
	viviendo2.setString(vida2);
	w.draw(viviendo1);
	w.draw(viviendo2);
	m_atk.setString(atk2);
	m_def.setString(def2);
	w.draw(m_atk);
	w.draw(m_def);
	nombre1.setString(p1.VerNombre());
	nombre2.setString(p2.VerNombre());
	w.draw(nombre1);
	w.draw(nombre2);
	w.display();
	if(Mano1.size()>4 && Mano2.size()>4 && cont==1)
		problemas=1;
}

bool VentanaPrincipal::Fun_Ventana(int v, string x)
{
	RenderWindow ventana(VideoMode(315,149),"YU-GI-OH!");
	ventana.setFramerateLimit(60);
	while(ventana.isOpen())
	{	
		ventana.requestFocus();
		int aceptar=0, cancelar=0;	
		Text texto;
		
		if(v==1)
			ven.loadFromFile("sinocancelar.jpg");
		else if(v==2)
		{
			ven.loadFromFile("ModoEfecto.png");
			x="¿Cambiar de modo o usar efecto?";
		}
		else if(v==3)
		{
			ven.loadFromFile("AtaqueDefensa.png");
			x="¿Invocar en Ataque o en defensa?";
		}
		veno.setTexture(ven);
		ventana.draw(veno);
		
		if (!fuente.loadFromFile("arial.ttf"));
		
		texto.setFont(fuente);
		texto.setString(x);
		texto.setCharacterSize(15);
		texto.setFillColor(sf::Color::Black);
		texto.setPosition(70,20);
		ventana.draw(texto);
		ventana.display();
		
		while(ventana.pollEvent(e)) 
		{
			if(e.type == Event::Closed && v!=2)
			{
				z=0;
				cancelar=1;
			}
			else if(e.type == Event::Closed && v==2)
			{
				z=1;
				ventana.close();	
			}
			while(sf::Mouse::getPosition(ventana).x>137 and sf::Mouse::getPosition(ventana).y>111 and sf::Mouse::getPosition(ventana).x<209 and sf::Mouse::getPosition(ventana).y<133 and  sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				z=0;
				aceptar=1;
			}
			while(sf::Mouse::getPosition(ventana).x>220 and sf::Mouse::getPosition(ventana).y>111 and sf::Mouse::getPosition(ventana).x<292 and sf::Mouse::getPosition(ventana).y<133 and  sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				z=0;
				cancelar=1;
			}
			
			if(aceptar==1)
			{
				ven.loadFromFile("Nada-c.png");
				ventana.close();
				return true;
			}
			else if(cancelar==1)
			{
				ven.loadFromFile("Nada-c.png");
				ventana.close();
				return false;
			}
		}
	}
}

void VentanaPrincipal::Info(string x1, string x2)
{
	RenderWindow info(VideoMode(332,149),"YU-GI-OH!");
	info.setFramerateLimit(60);
	
	while(info.isOpen())
	{	
		info.requestFocus();	
		ven2.loadFromFile("Atención.jpg");
		veno2.setTexture(ven2);
		sf::Font fuente;
		if (!fuente.loadFromFile("arial.ttf"));
		Text texto1, texto2;
		texto1.setString(x1);
		texto1.setFont(fuente);
		texto1.setCharacterSize(12);
		texto1.setFillColor(sf::Color::Black);
		texto1.setPosition(15, 70);
		if(x2!="")
		{
			texto2.setString(x2);
			texto2.setFont(fuente);
			texto2.setCharacterSize(12);
			texto2.setFillColor(sf::Color::Black);
			texto2.setPosition(15, 90);
		}
		info.draw(veno2);
		info.draw(texto1);
		info.draw(texto2);
		info.display();
		
		while(info.pollEvent(e)) 
		{
			if(e.type == Event::Closed)
				info.close();
		}
	}
}

void VentanaPrincipal::Atak()
{
	RenderWindow atak(VideoMode(277,99),"YU-GI-OH!");
	atak.setFramerateLimit(60);
	Texture at;
	Sprite atk;
	while(atak.isOpen())
	{		
		atak.requestFocus();
		at.loadFromFile("Batalla.jpg");
		atk.setTexture(at);
		atak.draw(atk);
		atak.display();
		
		if(Mouse::isButtonPressed(sf::Mouse::Left)) 
		{
			atak.close();
		}
	}
}

void VentanaPrincipal::CartaGrande(int i, RenderWindow &w)
{
	int k=i+1;
	vector<Sprite> Mano;
	vector<Sprite> C1, C2;
	p1=*j.VerJugador(1);
	p2=*j.VerJugador(2);
	if(jug==1)
	{
		Mano=Mano1;
		aux1=p1;
		aux2=p2;
		C1=Campo1;
		C2=Campo2;
	}
	else
	{
		Mano=Mano2;
		aux1=p2;
		aux2=p1;
		C1=Campo2;
		C2=Campo1;
	}
	if(k<=aux1.VerMano().size())
	{
		if(a==i && not Mano[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
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
		else if (Mano[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
		{
			string s=aux1.VerMano()[i].img;
			mos.loadFromFile(s);
			Cardmos1.setTexture(mos);
			Cardmos1.setPosition(2, 74); 
			Cardmos1.setScale(0.475, 0.475);
			a=i;
		}
	}
	if(k<=aux1.VerCampo().size() && aux1.VerCampo().size()>0)
	{
		if(a==i && not C1[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
		{
			Dorso.loadFromFile("Dorso.png");
			Cardmos.setScale(1, 1);
			Cardmos.setPosition(2, 74); 
			Cardmos.setTexture(Dorso);
			nadita.loadFromFile("Nada.png");
			Cardmos2.setTexture(nadita);
			Cardmos2.setPosition(2, 74); 
			Cardmos2.setScale(0.475, 0.475);
			a=0;
			atk2=" ";def2=" ";
		}
		else if (C1[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
		{
			string s=aux1.VerCampo()[i].img;
			mos.loadFromFile(s);
			Cardmos2.setTexture(mos);
			Cardmos2.setPosition(2, 74); 
			Cardmos2.setScale(0.475, 0.475);
			atk=aux1.VerCampo()[i].ataque;
			def=aux1.VerCampo()[i].defensa;
			atk1<<atk;def1<<def;
			atk2="Atk/ ";def2="Def/ ";
			atk2+=atk1.str();def2+=def1.str();
			atk1.str(std::string());def1.str(std::string());
			a=i;
		}
	}
	if(k<=aux2.VerCampo().size() && aux2.VerCampo().size()>0)
	{
		if(a==i && not C2[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
		{
			Dorso.loadFromFile("Dorso.png");
			Cardmos.setScale(1, 1);
			Cardmos.setPosition(2, 74); 
			Cardmos.setTexture(Dorso);
			nadita.loadFromFile("Nada.png");
			Cardmos3.setTexture(nadita);
			Cardmos3.setPosition(2, 74); 
			Cardmos3.setScale(0.475, 0.475);
			a=0;
		}
		else if (C2[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))))
		{
			string s=aux2.VerCampo()[i].img;
			mos.loadFromFile(s);
			Cardmos3.setTexture(mos);
			Cardmos3.setPosition(2, 74); 
			Cardmos3.setScale(0.475, 0.475);
			atk=aux2.VerCampo()[i].ataque;
			def=aux2.VerCampo()[i].defensa;
			atk1<<atk;def1<<def;
			atk2="Atk/ ";def2="Def/ ";
			atk2+=atk1.str();def2+=def1.str();
			atk1.str(std::string());def1.str(std::string());
			a=i;
		}
		
	}
}

void VentanaPrincipal::menu(RenderWindow &w)
{
	vector<Sprite> Mano;
	vector<Sprite> C;
	if(jug==1)
	{
		Mano=Mano1;
		C=Campo1;
	}
	else
	{
		Mano=Mano2;		
		C=Campo2;
	}
	for(int i=0;i<Mano.size();i++) 
	{
		CartaGrande(i, w);
		if (etapa!=4 && Mano[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
		{
			etapa=1;
			eleccion=i;
		}
	}
	for(int i=0;i<C.size();i++) 
	{
		CartaGrande(i, w);
		if (etapa!=4 && C[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(Fun_Ventana(2, ""))
			{
				etapa=2;
				eleccion=i;
			}
			else if(z==0)
			{
				etapa=3;
				eleccion=i;
			}
			else
			{ 
				etapa=0;
				el=11;
				eleccion=11;
				z=0;
			}
		}
		else if(etapa==4 && cont>1)
		{
			if(z==0)
				Atak();
			z=1;
			if(C[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
			{
				eleccion=i;
				z=0;
				el=0;
			}
		}
	}
}

int VentanaPrincipal::CaraCruz()
{
	int moneda=0;
	RenderWindow caracruz(VideoMode(466,227),"YU-GI-OH!");
	caracruz.setFramerateLimit(60);
	
	while(caracruz.isOpen())
	{		
		caracruz.requestFocus();
		ven3.loadFromFile("Cara o Cruz.png");
		veno3.setTexture(ven3);
		caracruz.draw(veno3);
		caracruz.display();
		
		if(Mouse::getPosition().x<233 && Mouse::isButtonPressed(Mouse::Left))
			moneda=1;
		else if (Mouse::getPosition().x>233 && Mouse::isButtonPressed(Mouse::Left))
			moneda=2;
		if(moneda!=0)
			caracruz.close();
	}
	if(moneda!=0)
	{
		cout<<"moneda: "<<moneda;
		p2.Matansa(p1, moneda);
		j.ActualizarPlayer(p1, p2);
		return 1;
	}
	return 0;
}

void VentanaPrincipal::Modo(int i, int turno)
{
	if(turno==1)
		aux1=p1;
	else
		aux1=p2;
	if(i<9)
	{
		if(not aux1.VerCampo()[i].cambio)
		{
			aux1.Cambiar(i);
			aux1.Cambio(i);
		}
		else
			Info("Esta carta ya cambió de modo en este turno", "");
	}
	else
	{
		if(i!=20)
		{
			i-=10;
			aux1.Cambiar(i);
		}
		else i-=20;
		aux1.Cambio(i);
	}
	
	if(turno==1)
	   j.ActualizarPlayer(aux1, aux2);
	else
		j.ActualizarPlayer(aux2, aux1);
	
	p1=*j.VerJugador(1);
	p2=*j.VerJugador(2);
	
	Tabla(1);
	Tabla(2);
	
	etapa=0;
}

int VentanaPrincipal::Invocacion(int eleccion, int turno)
{
	int dev=1;
	if(turno==1)
		aux1=p1;
	else
		aux1=p2;
	string s0=aux1.VerMano()[eleccion].monstruo, s="invocar a "+s0+"??";
	
	if(Fun_Ventana(1, s) && invoco==0 && (aux1.VerCampo().size()<5 || aux1.VerMano()[eleccion].estrellas>4))
	{
		if(aux1.VerMano()[eleccion].estrellas<5)
		{
			aux1.Invocar(eleccion+1);
			if(turno==1)
				j.ActualizarPlayer(aux1, aux2);
			else
				j.ActualizarPlayer(aux2, aux1);
			
			p1=*j.VerJugador(1);
			p2=*j.VerJugador(2);
			
			invoco=1;
			if(not Fun_Ventana(3, ""))
				eleccion=aux1.VerCampo().size()+9;
			else
				eleccion=20;
			Modo(eleccion, turno);
			dev=1;
		}
		else if(aux1.VerCampo().size()>0 && aux1.VerMano()[eleccion].estrellas>4 && aux1.VerMano()[eleccion].estrellas<7)
		{
			Info("Debe sacrificar 1 cartas", "");
			dev=20+eleccion;
		}
		else if(aux1.VerCampo().size()>0 && aux1.VerMano()[eleccion].estrellas>=7)
		{
			if(aux1.VerMano()[eleccion].monstruo!="Dragon Negro de Ojos Rojos" && aux1.VerCampo().size()>1)
			{
				Info("Debe sacrificar 2 cartas", "");	
				dev=30+eleccion;
			}
			else if(aux1.VerMano()[eleccion].monstruo=="Dragon Negro de Ojos Rojos" && aux1.VerCampo().size()>0)
			{
				Info("La carta seleccionada es el Dragon Negro de Ojos Rojos,", "sacrifique dos cartas o a la Cría de Ojos Rojos si la posee en campo");			
				dev=40+eleccion;
			}
			else
			{
				if(aux1.VerMano()[eleccion].estrellas>6)
				{
					Info("No tiene sacrificio para dar", "");	
					dev=5;
				}
			}
		}
		else
		{
			Info("No tiene sacrificio para dar", "");	
			dev=5;
		}
	}
	else if (aux1.VerCampo().size()==5)
	{
		Info("No puede tener mas de", "5 cartas en el campo");
		dev=1;
	}
	else if (invoco==1)
	{
		Info("Solo puede invocar una vez por turno", "");
		dev=1;
	}
	etapa=0;
	el=11;
	eleccion=11;
	z=0;
	return dev;
}

int VentanaPrincipal::Sacrificio(int aux, int prob, int &cdor, int turno, RenderWindow &w)
{
	int dev=0;
	vector<Sprite> Campo;
	vector<Sprite> Mano;
	p1=*j.VerJugador(1);
	p2=*j.VerJugador(2);
	if(turno==1)
	{
		Mano=Mano1;
		aux1=p1;
		aux2=p2;
		Campo=Campo1;
	}
	else
	{
		Mano=Mano2;
		aux1=p2;
		aux2=p1;
		Campo=Campo2;
	}
	for(size_t i=0;i<Campo.size();i++) 
	{
		CartaGrande(i, w);
		if ((prob==4 || prob==3) && Campo[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
		{						
			if(prob==4 && aux1.VerCampo()[i].monstruo=="Cria de Ojos Rojos")
			{
				dev=2;
				cdor=i;
			}
			else
			{	p1=*j.VerJugador(1);
			if(aux1.VerMano()[aux-1].monstruo=="Dragon Negro de Ojos Rojos" && aux1.VerCampo().size()<2)
			{
				Info("No puede invocar al Dragon Negro de Ojos Rojos", "No tiene un Sacrificio apropiado");
				dev=1;
			}
			else
			{
				dev=2;
				aux1.Cementerio(i);
			}
			}
		}
		if (prob==2 && Campo[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
		{		
			if(aux1.VerMano()[aux-1].monstruo=="Dragon Negro de Ojos Rojos")
			{
				aux1.Cementerio(cdor);
				aux1.Invocar(aux);
				if(turno==1)
					j.ActualizarPlayer(aux1, aux2);
				else
					j.ActualizarPlayer(aux2, aux1);
				
				p1=*j.VerJugador(1);
				p2=*j.VerJugador(2);
				invoco=1;
				if(not Fun_Ventana(3, ""))
					eleccion=aux1.VerCampo().size()+9;
				else
					eleccion=aux1.VerCampo().size()+19;
				Modo(eleccion, turno);
				if(turno==1)
					j.ActualizarPlayer(aux1, aux2);
				else
					j.ActualizarPlayer(aux2, aux1);
				
				p1=*j.VerJugador(1);
				p2=*j.VerJugador(2);
				cdor=0;
			}
			else
			{
				aux1.Cementerio(i);
				aux1.Invocar(aux);
				if(turno==1)
					j.ActualizarPlayer(aux1, aux2);
				else
					j.ActualizarPlayer(aux2, aux1);
				
				p1=*j.VerJugador(1);
				p2=*j.VerJugador(2);
				invoco=1;
				if(not Fun_Ventana(3, ""))
					eleccion=aux1.VerCampo().size()+9;
				else
					eleccion=aux1.VerCampo().size()+19;
				Modo(eleccion, turno);
				if(turno==1)
					j.ActualizarPlayer(aux1, aux2);
				else
					j.ActualizarPlayer(aux2, aux1);
				
				p1=*j.VerJugador(1);
				p2=*j.VerJugador(2);
			}
			dev=1;
		}
		if(turno==1)
			j.ActualizarPlayer(aux1, aux2);
		else
			j.ActualizarPlayer(aux2, aux1);
		
		if(dev!=0)
			return dev;
	}
	for(size_t i=0;i<Mano.size();i++) 
	{
		if (prob==6 && Mano[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
		{	
			aux1.Sacrificar(i);
			dev=7;
		}
		
		if(turno==1)
			j.ActualizarPlayer(aux1, aux2);
		else
			j.ActualizarPlayer(aux2, aux1);
		
		if(dev!=0)
			return dev;
	}
	return prob;
}

void VentanaPrincipal::Doce()
{
	int nr=0;
	for(size_t i=0;i<p2.VerCampo().size();i++)
	{
		m=0; 
		if(p2.VerCampo()[i].efecto==12)
		{
			for(size_t i=0;i<p2.VerCementerio().size();i++) 
			{
				if(p2.VerCementerio()[i].monstruo=="Mago Obscuro")
					m++;
			}
			aumento=300*m;
			p2.MasAtaque(i, aumento);
		}  
		j.ActualizarPlayer(p1, p2);
		p2=*j.VerJugador(2);
	}
}

int VentanaPrincipal::Efecto(int turno, int problemas, RenderWindow &w)
{
	int CoC=0, dev=3;
	if(p2.VerCampo()[eleccion].efecto==0 || p2.VerCampo()[eleccion].efecto==6 || p2.VerCampo()[eleccion].efecto==12)
	{
		Info("no tiene efecto", "");
		eleccion=11;
		etapa=0;
		dev=-2;
	}
	else
	{
		if(p2.VerCampo()[eleccion].efecto!=2)
		{
			//SI NO HAY CARTAS
			{
			if(p1.VerCampo().size()==0)
			{		
				Info("el otro player no tiene cartas en el", " campo, elija otra carta para usar efecto");
				eleccion=11;
				etapa=0;
				dev=-1;
			}
		}
		if(p2.VerCampo()[eleccion].efecto!=4 && dev!=-1)
		{
			if(p2.VerCampo()[eleccion].efecto==5 &&  p2.VerCampo().size()==5)
			{
				Info("No puede usar ese efecto, ya que", "la carta a robar no entra en su campo");
				eleccion=11;
				etapa=0;
			}
			else
			{
				if(at1==10){
					if(z==0)
						Info("Elegir carta rival", "");
					z++;
					for(size_t i=0;i<p1.VerCampo().size();i++) 
					{
						CartaGrande(i, w);
						if (Campo1[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
						{
							at1=i;
							if(p2.VerCampo()[eleccion].efecto==3)
							{
								problemas=15;
								z=0;
							}
						}
					}		
				}
				if(problemas==15 && p2.VerCampo()[eleccion].efecto==3 && at2==10)
				{
					if(z==0)
						Info("Elegir sacrificio", "");
					z++;
					for(size_t i=0;i<p2.VerMano().size();i++) 
					{
						CartaGrande(i, w);
						if (Mano2[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
							at2=i;
					}
				}
				if(at1!=10 && p2.VerCampo()[eleccion].efecto!=3)
				{
					j.Efecto(eleccion, at1, 0);
					
					p1=*j.VerJugador(1);
					p2=*j.VerJugador(2);
					
					Tabla(1);
					Tabla(2);
					
					at1=10;
					etapa=0;
					eleccion=11;
					dev=0;
					problemas=1;
				}
				else if (at1!=10 && at2!=10 && p2.VerCampo()[eleccion].efecto==3)
				{
					j.Efecto(eleccion, at1, at2);
					
					p1=*j.VerJugador(1);
					p2=*j.VerJugador(2);
					
					Tabla(1);
					Tabla(2);
					
					at1=10;
					etapa=0;
					eleccion=11;
					dev=0;
					problemas=1;
				}
			}
		}
		else if(dev!=-1)
		{	
			cout<<"entra 2"<<endl;
			CoC=CaraCruz();
			eleccion=11;
			etapa=0;
			if(CoC==1)
				dev=1;
			
		}
		}
		else
		{
			cout<<"entra "<<endl;
			j.Efecto(eleccion, 0, 0);	
			eleccion=11;
			etapa=0;
			dev=2;
		}
	}
	return dev;
}

void VentanaPrincipal::Ataque(int turno, int atacante, RenderWindow &w)
{
	int atacada=10;
	vector<Sprite> C;
	if(turno==1)
	{
		aux1=p1;
		aux2=p2;
		C=Campo2;
	}
	else
	{
		aux1=p2;
		aux2=p1;
		C=Campo1;
	}
	if(aux1.VerCampo()[atacante].aod)
	{
		if(aux1.VerCampo()[atacante].ataco)
		{
			Info("Esta carta ya ataco en este turno", "");
			atacante=11;
			el=11;
		}
		else if(z==0 && aux2.VerCampo().size()>0)
						 Info("Elegir carta rival", "");
		for(size_t i=0;i<aux2.VerCampo().size();i++) 
		{
			CartaGrande(i, w);
			if (C[i].getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
				atacada=i;
		}
		if(aux2.VerCampo().size()==0)
		{
			if(atacante!=11)
				atacada=-1;
		}
		else if(aux2.VerCampo()[atacada].efecto==6 && aux2.VerCampo().size()>1)
		{
			Info("No puede atacar a Valquiria del mago", "mientras haya otra opcion de ataque");
			atacada=10;
		}
		if(atacada!=10)
		{
			j.Atacar(atacada, atacante, turno);
			p1=*j.VerJugador(1);
			p2=*j.VerJugador(2);
			
			Tabla(1);
			Tabla(2);
			
			holi1.str(std::string());
			holi2.str(std::string());
			v1=p1.VerVida();
			v2=p2.VerVida();
			holi1<<v1;
			holi2<<v2;
			vida1=holi1.str();
			vida2=holi2.str();
			
			atacante=11;
			el=11;
		}
	}
	else
	{
		Info("No puede atacar con una carta en defensa", "");
		el=11;
		atacante=11;
	}
	z=1;
}

void VentanaPrincipal::MostrarGanador()
{
	RenderWindow Ganador(VideoMode(332,149),"YU-GI-OH!");
	Ganador.setFramerateLimit(60);
	
	while(Ganador.isOpen())
	{		
		Ganador.requestFocus();
		ven2.loadFromFile("Ganador.jpg");
		veno2.setTexture(ven2);
		sf::Font fuente;
		if (!fuente.loadFromFile("arial.ttf"));
		Text texto;
		texto.setFont(fuente);
		texto.setCharacterSize(19.5);
		texto.setFillColor(sf::Color::Black);
		texto.setStyle(Text::Bold);
		texto.setPosition(195, 80);
		
		while(Ganador.pollEvent(e)) 
		{
			if(e.type == Event::Closed)
			{
				Ganador.close();
			}
		}
		if(j.VerGanador()!="1")
		{
			string s=j.VerGanador();
			texto.setString(s);
		}
		else
		   texto.setString("¡¡EMPATEEE!!");
		
		Ganador.draw(veno2);
		Ganador.draw(texto);
		Ganador.display();
	}
}

void VentanaPrincipal::Cambio(Estructura &estr, RenderWindow &w)
{
	Draw(w);
	Doce();
	//Next Phase
	{
		while (Np1.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) && Mouse::isButtonPressed(sf::Mouse::Left))
			at=1;
		
		if(at==1)
		{
			if(jug==1)
				aux1=p1;
			else
				aux1=p2;
			
			if(etapa!=4 && aux1.VerCampo().size()>0)
				etapa=4;
			else if(etapa==4)
			{
				etapa=0;
				el=11;
				eleccion=11;
				z=0;
			}
			else
				Info("No tienes cartas para atacar", "");
			at=0;
		}
	}
	if(problemas==1)
		menu(w);
	else if(problemas!=15)
		etapa=0;
	
	switch(etapa)
	{
	case 1:
		problemas=Invocacion(eleccion, jug);
		break;
	case 2:
		Modo(eleccion, jug);
		break;
	case 3:
		if(jug==2)
			efecto=Efecto(jug, eleccion, w);
		else
		{
			Info("no tiene efecto", "");
			etapa=0;
		}
		break;
	case 4:
		if(el!=11 && cont>1)
			Ataque(jug, eleccion, w);
		else if(cont<2)
		{
			Info("No puede atacar en la primera ronda", "");
			etapa=0;
		}
		w.draw(shape);
		w.display();
		break;
	}
	
	p1=*j.VerJugador(1);
	p2=*j.VerJugador(2);
	
	//AUX
	{
		if(problemas>39)
		{
			aux=problemas-39;
			problemas/=10;
		}
		else if(problemas>29)
		{
			aux=problemas-29;
			problemas/=10;
		}
		else if(problemas>19)
		{
			aux=problemas-19;
			problemas/=10;
		}
	}
	
	//End Turn
	if (problemas!=6 && etapa!=4 && (problemas==7 || et1.getGlobalBounds().contains(w.mapPixelToCoords(sf::Mouse::getPosition(w))) and sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		if(problemas==7)
		{
			cout<<"problema 7"<<endl;
			if(jug==1)
				p1.Juntar();
			else
				p2.Juntar();
			j.ActualizarPlayer(p1, p2);
			problemas=1;
		}
		else if(Fun_Ventana(1, "¿Desea pasar el Turno?"))
		{
			while(not Mouse::isButtonPressed(sf::Mouse::Left))
			{
				for(size_t j=0;j<p1.VerMano().size();j++)
				{
					nadita.loadFromFile("Nada.png");
					auxiliar1.setTexture(nadita);
					auxiliar1.setScale(0.12,0.12);
					if(j<5)
					{
						auxiliar1.setPosition(417+(j*82), 394);
						M1[j].setPosition(417+(j*82), 394);
					}
					else
					{
						auxiliar1.setPosition(458+((j-4)*82), 487.2);
						M1[j].setPosition(458+((j-4)*82), 487.2);
					}
					if(Mano1.size()<=p1.VerMano().size())
					   Mano1.resize(j+1);
					else if(Mano1.size()!=p1.VerMano().size())
						Mano1.resize(p1.VerMano().size());
					Mano1[j]=auxiliar1;
					w.draw(M1[j]);
					w.draw(Mano1[j]);
				}
				for(size_t j=0;j<p2.VerMano().size();j++)
				{
					nadita.loadFromFile("Nada.png");
					auxiliar2.setTexture(nadita);
					auxiliar2.setScale(0.12,0.12);
					if(j<5)
					{
						auxiliar2.setPosition(417+(j*82), 148);
						M2[j].setPosition(417+(j*82), 148);
					}
					else
					{
						auxiliar2.setPosition(458+((j-4)*82), 54.8);
						M2[j].setPosition(458+((j-4)*82), 54.8);
					}
					if(Mano2.size()<=p2.VerMano().size())
					   Mano2.resize(j+1);
					else if(Mano2.size()!=p2.VerMano().size())
						Mano2.resize(p2.VerMano().size());
					Mano2[j]=auxiliar2;
					w.draw(M2[j]);
					w.draw(Mano2[j]);
				}
				w.display();
			}
			cont++;
			jug=j.EleccionTurno(cont);
			if(jug==1)
			{
				p1.Reinicio();
				if(p1.VerMano().size()<7)
				{
					p1.Juntar();
					j.ActualizarPlayer(p1, p2);
				}
				else if(Fun_Ventana(1, "Supera las 7 cartas en mano, ¿Sacrificar?"))
				   problemas=6;
			}
			else
			{
				p2.Reinicio();
				if(p2.VerMano().size()<7)
				{
					p2.Juntar();
					j.ActualizarPlayer(p1, p2);
				}
				else if(Fun_Ventana(1, "Supera las 7 cartas en mano, ¿Sacrificar?"))
				   problemas=6;
			}
			invoco=0;
		}
	}
	switch(problemas)
	{
	case 2:	
		problemas=Sacrificio(aux, problemas, cdor, jug, w);
		break;
	case 3:
		problemas=Sacrificio(aux, problemas, cdor, jug, w);
		break;
	case 4:
		problemas=Sacrificio(aux, problemas, cdor, jug, w);
		break;
	case 5:
		problemas=1;
		break;
	case 6:
		problemas=Sacrificio(aux, problemas, cdor, jug, w);
	}
	
	p1=*j.VerJugador(1);
	p2=*j.VerJugador(2);
	if(j.Finalizado())
	{
		MostrarGanador();
		estr.CambioEscena(new Menu());
	}
}
