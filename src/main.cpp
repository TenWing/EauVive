#include <iostream>
#include "modele/GestionMaree.hpp"
#include "modele/GestionStade.hpp"
#include "modele/Calendrier.hpp"

int main(void)
{

    GestionMaree g;
    
    std::cout << "Hello World!" << std::endl;
    
    g.coefficient = 60;
    
    std::cout << "Marée de " << g.coefficient << std::endl;
    
    for(int i = 0; i < 24; i++)
    {
        std::cout << i << "h niveau : " << g.lireNiveauMaree() << std::endl;
        Calendrier::avancerTemps();
    }   
    
    return 0;
}
