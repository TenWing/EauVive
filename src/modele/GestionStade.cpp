/*
 * GestionStade.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "GestionStade.hpp"

GestionStade::GestionStade()
{
	// TODO Auto-generated constructor stub

}

bool GestionStade::verifierFinSeance()
{
	double niveauMaree = maree.lireNiveauMaree();

	//si le niveau de la mer est au dessus de 1 m alors on arrête la séance
	if(niveauMaree > 1)
		return true;

	return false;
}

double GestionStade::calculerLameEau()
{
	return 0;
}

