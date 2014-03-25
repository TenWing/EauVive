#include <iostream>
#include "modele/GestionMaree.hpp"
#include "modele/GestionStade.hpp"
#include "modele/Calendrier.hpp"
#include "vue/Console.hpp"

int main(void)
{

    GestionMaree g;
    
    g.coefficient = 60;
    
    std::cout << "Maree de " << g.coefficient << std::endl;
    
    for(int i = 0; i < 24; i++)
    {
        std::cout << i << "h niveau : " << g.lireNiveauMaree() << std::endl;
        Calendrier::avancerTemps();
    }   

    Console affichage;

    affichage.lancer();
    
    return 0;
}
