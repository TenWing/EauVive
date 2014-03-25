/*
 * Vanne.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "Vanne.hpp"

Vanne::Vanne() : hauteur(0)
{

}

double Vanne::getHauteur()
{
    return hauteur;
}

void Vanne::ouvrir(double lameEau)
{
	//On change la hauteur de la vanne
	hauteur -= lameEau;
}
