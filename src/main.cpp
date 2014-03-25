#include <iostream>
#include "modele/GestionMaree.hpp"
#include "modele/GestionStade.hpp"

int main(void)
{
    GestionMaree g;
    
    std::cout << "Hello World!" << std::endl;
    
    std::cout << "Marée de 95" << std::endl;
    
    for(int i = 0; i < 24; i++)
        std::cout << i << "h niveau : " << g.lireNiveauMaree() << std::endl;
    
    GestionStade s;

    double lame = 0.3f;

    while(lame < 0.55f)
    {
    	std::cout << "debit pour lame de " << lame << " : " << s.deduitQdeH(lame) << std::endl;
    	lame = lame + 0.02;
    }

    return 0;
}
