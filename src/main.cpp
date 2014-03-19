#include <iostream>
#include "modele/GestionMaree.hpp"

int main(void)
{
    GestionMaree g;
    
    std::cout << "Hello World!" << std::endl;
    
    std::cout << "Marée de 95" << std::endl;
    
    for(int i = 0; i < 24; i++)
        std::cout << i << "h niveau : " << g.lireNiveauMaree() << std::endl;
    
    return 0;
}
