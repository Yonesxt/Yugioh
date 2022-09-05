#include "Juego.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Juego::Juego(string a, string b):p1(a, "Mazo1.dat"), p2(b, "Mazo2.dat")
{
	
}

void Juego::Atacar(int i1, int i2, int random)
{
	int a=0;
	Carta atacante, atacada;
	Player y(" ", ""), z(" ", "");
	if(random==1)
	{
		y=p1;
		z=p2;
	}
	if(random==2)
	{
		y=p2;
		z=p1;
	}
	atacante=y.Una(i2);
	if(i1>=0)
		atacada=z.Una(i1);
	if(atacada.aod)
	{
		if(atacante.ataque>atacada.ataque)
		{
			int d=atacante.ataque-atacada.ataque;
			if(i1>=0)
			{
				if(y.VerCampo()[i2].efecto==11)
				{
					y.Cambiar(i2);	
					y.Cambio(i2);
				}
				if(z.VerCampo()[i1].efecto==7)
					a=-1;
				else if(z.VerCampo()[i1].efecto==10)
				{
					y.Cementerio(i2);
					d=0;
				}
				z.Cementerio(i1);
			}
			z.Danio(d);
		}
		else if(atacante.ataque<atacada.ataque)
		{
			int d=atacada.ataque-atacante.ataque;
			if(y.VerCampo()[i2].efecto==10)
			{
				z.Cementerio(i1);
				d=0;
			}
			y.Cementerio(i2);
			y.Danio(d);
		}
		else if(atacante.ataque==atacada.ataque)
		{
			y.Cementerio(i2);
			if(z.VerCampo()[i1].efecto==7)
				a=-1;
			z.Cementerio(i1);
		}
	}
	else
	{
		if(atacante.ataque>atacada.defensa)
		{
			if(z.VerCampo()[i1].efecto==7)
				a=-1;
			else if(z.VerCampo()[i1].efecto==10)
				y.Cementerio(i2);
			if(y.VerCampo()[i2].efecto==11)
			{
				int d=atacante.ataque-atacada.defensa;
				z.Danio(d);
				y.Cambiar(i2);	
				y.Cambio(i2);
			}
			z.Cementerio(i1);
		}
		else if(atacante.ataque<atacada.defensa)
		{
			int d=atacada.defensa-atacante.ataque;
			y.Danio(d);
		}
	}
	if(atacante.efecto==9)
	   y.Cambiar(i2);	
	
	if(y.VerCampo().size()>=0)
	{
		y.Ataco(i2);
		y.Cambio(i2);
	}	
	if(random==1)
	{
		p1=y;
		p2=z;
		if(a==-1)
		{
			p2.Juntar();
			p2.Juntar();
		}
	}
	else
	{
		p2=y;
		p1=z;
	}
}


int Juego::Efecto (int c, int at1, int at2) 
{
	if(c!=-1)
	{
		int algo=0;
		switch(p2.VerCampo()[c].efecto)
		{
			case 1:
				p2.Imitador(p1, c, at1);
				break;
			case 2:
				p2.MasDefensa(c);
				break;
			case 3:
				p1.Cementerio(at1);
				p2.Sacrificar(at2);
				break;
			case 4:
				p2.Matansa(p1, at1);
				break;
			case 5:
				p2.Control(p1, at1);
				break;
		}
		return algo;
	}
	else return 0;
}
int Juego::EleccionTurno(int c)
{
	cont=c;
	srand(time(NULL));
	if(cont==1)
		random=rand()%2+1;
	else
	{
		if(random==1)
			random=2;
		else
			random=1;
	}
	return random;
}

string Juego::VerGanador()
{
	if(not p1.EstaVivo())
		return p2.VerNombre();
	else if (not p2.EstaVivo())
		return p1.VerNombre();
	else if(p2.VerVida()>p1.VerVida())
		return p2.VerNombre();
	else if(p1.VerVida()>p2.VerVida())
		return p1.VerNombre();
	else
		return "1";
}

bool Juego::Finalizado()
{
	if(not p1.EstaVivo()||not p2.EstaVivo())
		return true;
	else if(not p1.TieneCartas()||not p2.TieneCartas())
		return true;
	else
		return false;
}
