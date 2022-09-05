#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <string>
#include <sstream>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "juego.h"
#include "Escena.h"
#include <SFML/Graphics/CircleShape.hpp>
using namespace std;
using namespace sf;

class VentanaPrincipal : public Escena{
public:
	VentanaPrincipal(Juego juego, string n1, string n2);
	int Tabla(int jug);
	void Draw(RenderWindow &w) override;
	void Cambio(Estructura &e, RenderWindow &w) override;
	bool Fun_Ventana(int v, string x);
	void Info(string x1, string x2);
	void Atak();
	void MostrarGanador();
	void CartaGrande(int i, RenderWindow &w);
	void menu(RenderWindow &w);
	int CaraCruz();
	void Modo(int i, int turno);
	int Invocacion(int turno, int invoco);
	int Sacrificio(int aux, int prob, int &cdor, int turno, RenderWindow &w);
	void Doce();
	int Efecto(int turno, int problemas, RenderWindow &w);
	void Ataque(int turno, int atacante, RenderWindow &w);
	int SizeMano(int x)
	{
		if(x==1) return Mano1.size();
		else return Mano2.size();
	};
private:
	Juego j;
	Player p1, p2, aux1, aux2;
	int m=0, a=0, at1=10, at2=1, cont=1, efecto=3, v1, v2, aumento, at=0, problemas=8, jug=0, aux=0, cdor=0, invoco=0, etapa=0, el=11, eleccion=11, z=0;
	string vida1, vida2, atk2, def2;
	stringstream holi1, holi2, atk1, def1; 
	int atk, def; 
	CircleShape shape;
	Font fuente_vida, fuente;
	Text nombre1, nombre2, viviendo1, viviendo2, m_atk, m_def;
	Event e;
	Texture ven, ven2, ven3;
	Sprite veno, veno2, veno3;
	Texture Dorso;
	Texture nadita;
	Texture t; //del fondo
	Sprite s;	//del fondo
	Texture et;	//del endturn1
	Sprite et1;	// del endturn1
	Texture Np; //del endturn2
	Sprite Np1; //del endturn2
	Sprite Cardmos, Cardmos1, Cardmos2, Cardmos3;
	Texture mos;
	Texture Mazo1; 
	Sprite Mazoim1, Mazoim2;
	Texture tablerocard_textu;	
	Sprite tablerocard;
	Texture Card1, Card2; 
	Sprite auxiliar1, auxiliar2, Ca1, Ca2, ca;
	vector<Sprite> Mano1, Mano2, Campo1, Campo2, M1, M2;
};

#endif

