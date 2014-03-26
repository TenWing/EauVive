#include "Console.hpp"
#include "../modele/GestionStade.hpp"
#include <iostream>
#include <string>

Console::Console() : stade()
{

}

void Console::lancer()
{
	bool go = true;
	std::string str;

	while(go)
	{
		stade.automatique();
		if(stade.requiertIntervention())
		{
			std::cout << "Veuillez s'il vous plait, faire evacuer tous les kayakistes de la riviere artificielle " << std::endl;
		}
		std::cin.ignore();
		stade.finSeance();
		std::cout << stade.description() << std::endl;

		std::cout << "Finir l'application " << std::endl;
		std::cin >> str;

		if(str == "oui" || str == "o")
		{
			go = false;
		}
		std::cout << "--------------" << std::endl;
	}	
}