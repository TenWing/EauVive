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
	//On récupère le débit necessaire pour calculer la lame d'eau
	double debit = seance.getDebit();

	double lame = calculerLameEau();

	omniflots.ouvrir(lame);	
}

void GestionStade::commencerSeance()
{
	//tant que la séance n'est pas terminée
	while(!verifierFinSeance())
	{
		effectuerSeance();
	}
}

//Formule : H² = Q / ( g . sqrt(2) . L . g . m)
double GestionStade::calculerLameEau()
{
	return reserve - omniflots.getHauteur();
}

double calculeM(double Hauteur, double Largeur)
{
	return 0.525f * (1 + (1 / 1000*Hauteur + 1.6f) ) * (1 + 0.55f * Hauteur*Hauteur / ((Hauteur+Largeur)*(Hauteur+Largeur)))
}

