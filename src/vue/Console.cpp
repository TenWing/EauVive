#include "Console.hpp"
#include "../modele/GestionStade.hpp"
#include <iostream>
#include <string>

Console::Console() : stade()
{

}

void Console::lancer()
{
	stade.automatique();
	if(stade.requiertIntervention())
	{
		std::cout << "Veuillez s'il vous plait, faire evacuer tous les kayakistes de la riviere artificielle " << std::endl;
	}
	std::cin.ignore();
	stade.finSeance();
	std::cout << stade.description() << std::endl;
}