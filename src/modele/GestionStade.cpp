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

	//si le niveau de la mer est au dessus d'une valeur limite alors on arrête la séance
	if(niveauMaree > 5)
		return true;

	//Si le niveau de la résèrve est épuisé alors on arrête la séance
	if(reserve <= 0)
		return true;

	return false;
}

void GestionStade::effectuerSeance()
{
	double lame = calculerLameEau();
	
}

void GestionStade::commencerSeance()
{
	double debit = seance.getDebit();

	//tant que la séance n'est pas terminée
	while(!verifierFinSeance())
	{
		effectuerSeance();
	}
}

double GestionStade::calculerLameEau()
{
	return 0;
}

