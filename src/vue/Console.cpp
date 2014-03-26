#include "Console.hpp"
#include "../modele/GestionStade.hpp"
#include "../modele/Calendrier.hpp"
#include <iostream>
#include <string>

 Console::Console():stade()
{

}

// heure séance, type séance, coeff marée
void Console::demanderInformations()
{

    std::cout << "A quel heure voulez vous commencez la simulation?" << std::endl;
    std::cout << "(Entrez un nombre entier correspondant a l'heure)" << std::endl;

    std::cin >> Calendrier::heure;
    Calendrier::heure %= 12;

    std::cout << "Quel type de séance voulez vous?" << std::endl;
    std::cout << "(1) Entrainement" << std::endl;
    std::cout << "(2) Intermediaire" << std::endl;
    std::cout << "(3) Confirme" << std::endl;
    std::cout << "(4) Competition" << std::endl;

    int numero;

    std::cin >> numero;

    switch (numero) {
        case 1:
            stade.changeSeance(Seance(TypeProgramme::Entrainement));
            break;
            
        case 2:
            stade.changeSeance(Seance(TypeProgramme::Intermediaire));
            break;
            
        case 3:
            stade.changeSeance(Seance(TypeProgramme::Confirme));
            break;
            
        case 4:
            stade.changeSeance(Seance(TypeProgramme::Competition));
            break;
            
        default:
            break;
    }

    std::cout << "Quel est le coefficient de la marée?" << std::endl;
    std::cout << "(Entrez un nombre entre 45 et 95)" << std::endl;

    std::cin >> numero;
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
