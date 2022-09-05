#include "CartasenJuego.h"
#include <fstream>
#include <tuple>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

CartasenJuego::CartasenJuego(string arch) 
{
	fstream bin(arch, ios::binary|ios::in);
	Carta c;
	srand(time(NULL));
	bin.seekg(0);
	for(size_t i=0;i<18;i++) 
	{ 
		bin.read(reinterpret_cast<char*>(&c),sizeof(c));
		mazo.push_back(c);
	}
	random_shuffle(mazo.begin(), mazo.end());
	
	for(size_t i=mazo.size()-1; i>mazo.size()-6; i--) 
	{
		c=mazo[i];
		cartamano.push_back(c);
	}
	mazo.resize(mazo.size()-5);	
}

void CartasenJuego::SacardelMazo()
{
	int i=mazo.size()-1;
	Carta c = mazo[i]; 
	cartamano.push_back(c);
	mazo.erase(mazo.end());
}

void CartasenJuego::Bajar(int a)
{
	cartacampo.push_back(cartamano[a-1]);
	cartamano.erase(cartamano.begin()+a-1);
}

void CartasenJuego::Modo(int i)
{
	if(cartacampo[i].aod)
		cartacampo[i].aod=false;
	else
		cartacampo[i].aod=true;
}


void CartasenJuego::Cem(int i)
{
	Carta c=cartacampo[i];
	cementerio.push_back(c);
	cartacampo.erase(cartacampo.begin()+i);
}

void CartasenJuego::Sacrificio(int i)
{
	Carta c=cartamano[i];
	cementerio.push_back(c);
	cartamano.erase(cartamano.begin()+i);
}

void CartasenJuego::YaAtaco(int i)
{
	cartacampo[i].ataco=true;
}

void CartasenJuego::YaCambio(int i)
{
	cartacampo[i].cambio=true;
}

void CartasenJuego::Imitar (Carta c, int i) 
{
	cartacampo[i].ataque=c.ataque;
	cartacampo[i].defensa=c.defensa;
}

void CartasenJuego::Defensa (int i) 
{
	cartacampo[i].defensa+=500;
}

void CartasenJuego::Ataque (int i, int a) 
{
	cartacampo[i].ataque=2000+a;
	
}

void CartasenJuego::Erase(int i)
{
	cartacampo.erase(cartacampo.begin()+i);
}

void CartasenJuego::reinicio()
{
	for(size_t i=0;i<cartacampo.size();i++) 
	{
		cartacampo[i].cambio=false;
		cartacampo[i].ataco=false;
	}
}
