/*
 * Vanne.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "Vanne.hpp"
#include "TypeVanne.hpp"

Vanne::Vanne() : hauteur(0), type(TypeVanne::OMNIFLOTS), fermee(false), affalee(true)
{

}

Vanne::Vanne(TypeVanne type, bool fermee) : hauteur(0), type(type), fermee(fermee), affalee(!fermee)
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

void Vanne::changeHauteur(double hauteur)
{
	this->hauteur = hauteur;
}

bool Vanne::estAffalee()
{
	return affalee;
}

bool Vanne::estFermee()
{
	return fermee;
}

void Vanne::affaler()
{
	affalee = true;
	fermee = false;
}

void Vanne::suivreMaree(double niveau)
{
	hauteur = niveau - 0.03d;
}

void Vanne::ouvre()
{
	affalee =false;
	fermee =false;
}

bool Vanne::estOuverte()
{
	return (!affalee && !fermee);
}