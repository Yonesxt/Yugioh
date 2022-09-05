#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include "Estructura.h"
using namespace std;
using namespace sf;

int main(int argc, char *argv[])
{
	//CARGA 
	
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sf::Music music;
	music.openFromFile("yu-gi-oh.ogg");
	music.setLoop(true);
	music.play();
	music.setVolume(0);
	
	Estructura e;
	e.Arranca();
	
	return 0;
}
