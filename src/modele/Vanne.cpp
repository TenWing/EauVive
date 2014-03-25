/*
 * Vanne.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "Vanne.hpp"
#include "TypeVanne.hpp"

Vanne::Vanne() : hauteur(0), type(TypeVanne::OMNIFLOTS), fermee(true), affalee(false)
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

void Vanne::changeAffalee(bool affalee)
{
	this->affalee = affalee;
}

void Vanne::changeFermee(bool fermee)
{
	this->fermee = fermee;
}

bool Vanne::estAffalee()
{
	return affalee;
}

bool Vanne::estFermee()
{
	return fermee;
}