/*
 * GestionStade.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "GestionStade.hpp"
#include <tgmath.h>
#include <cmath>
#include <iostream>

GestionStade::GestionStade() : NGF(5)
{

}


void GestionStade::automatique()
{
	
}

bool GestionStade::verifierFinSeance()
{
	double niveauMaree = maree.lireNiveauMaree();

	//si le niveau de la mer est au dessus du 0NGF+ ici 5m alors on arrête la séance
	if(niveauMaree >= NGF)
		return true;

	//Si le niveau de la résèrve est épuisé alors on arrête la séance
	if(reserve <= NGF)
		return true;

	return false;
}

void GestionStade::effectuerSeance()
{
	//On calcule la lame d'eau = la hauteur dont la vanne doit se baisser pour laisser couleur un débit constant
	double lame = calculerLameEau();

	//on indique à la vanne de s'ouvrir pour créer la lame d'eau
	omniflots.ouvrir(lame);	

	//On change le niveau de la reserve
	reserve -= lame;
}

void GestionStade::commencerSeance()
{
	//tant que la séance n'est pas terminée
	while(!verifierFinSeance())
	{
		//On effectue la séance
		effectuerSeance();
	}
}

//Formule : H² = Q / ( g . sqrt(2) . L . g . m) et L = 7 pour omniflots
double GestionStade::calculerLameEau()
{
	switch(seance.getProgramme())
	{
		case ENTRAINEMENT :
			return 0.3f;

		case INTERMEDIAIRE :
			return 0.38f;

		case CONFIRME :
			return 0.45f;

		case COMPETITION :
			return 0.52f;

		default:
			return 1;
	}
}

double GestionStade::calculeM(double Hauteur, double Largeur)
{
	return 0.525f * (1 + 1 / ((1000*Hauteur) + 1.6f) ) * (1 + 0.55f * (pow(Hauteur,2) / pow(Hauteur+Largeur,2)));
}

double GestionStade::deduitQdeH(double H)
{
	double m = calculeM(H, 7);

	double q =  (m * pow(H,2) * sqrt(2) * 9.81f * 7);

	return q;
}

