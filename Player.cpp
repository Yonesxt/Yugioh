#include "Player.h"
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Player::Player(string nom, string a) : c(a)
{
	vida=8000;
	nombre=nom;
}

Carta Player::Una(int i)
{
	vector<Carta> aux = c.VerC();
	return aux[i];
}

void Player::Invocar(int p)
{
	c.Bajar(p);
}

void Player::Cambiar(int i)
{
	c.Modo(i);
}

void Player::Imitador (Player &p, int i1, int i2) 
{
	Carta aux=p.VerCampo()[i2];
	c.Imitar(aux, i1);
}

int Player::EstrellasCampo()
{
	int aux=0;
	for(size_t i=0;i<c.VerC().size();i++) 
	{
		aux+=c.VerC()[i].estrellas;
	}
	return aux;
}

void Player::MasDefensa (int i) 
{
	c.Defensa(i);
}

void Player::MasAtaque (int i, int a) 
{
	c.Ataque(i, a);
}

void Player::Camicase (Player &p, int i1, int i2) 
{
	i2--;
	c.Cem(i1);
	p.Cementerio(i2);
}

void Player::Matansa (Player &p, int i1) 
{
	srand(time(NULL));
	int r=rand()%2+1;
	if(i1==r)
	{
		for(int i=p.VerCampo().size()-1;i>=0;i--) 
			p.Cementerio(i);
	}
	else
	{
		for(int i=c.VerC().size()-1;i>=0;i--)
			c.Cem(i);
	}
}

void Player::Control (Player &p, int i1) 
{
	Carta aux=p.VerCampo()[i1];
	p.Borrar(i1);
	c.Agregar(aux);
}

void Player::Ataco(int i)
{
	c.YaAtaco(i);
}

void Player::Cambio(int i)
{
	c.YaCambio(i);
}

Carta Player::ElegirRival(Player &p, int i)
{
	return p.Una(i);
}

void Player::Danio(int algo)
{
	vida=vida-algo;	
}

void Player::Cementerio(int i)
{
	c.Cem(i);
}

void Player::Sacrificar(int i)
{
	c.Sacrificio(i);
}

bool Player::EstaVivo()
{
	if(vida<=0)
		return false;
	else 
		return true;
}

bool Player::TieneCartas()
{
	if(c.Mazo()==0)
		return false;
	else
		return true;
}

void Player::Reinicio()
{
	c.reinicio();
}
