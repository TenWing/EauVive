#include "Console.hpp"
#include "../modele/GestionStade.hpp"
#include <iostream>

Console::Console() : stade()
{

}

void Console::lancer()
{
	stade.automatique();
	std::cout << stade.description() << std::endl;
}