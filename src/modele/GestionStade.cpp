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

bool GestionStade::verifierFinSeance()
{
	double niveauMaree = maree.lireNiveauMaree();

	//si le niveau de la mer est au dessus du 0NGF+ ici 5m alors on arrête la séance
	if(niveauMaree > NGF)
		return true;

	//Si le niveau de la résèrve est épuisé alors on arrête la séance
	if(reserve <= NGF)
		return true;

	return false;
}

void GestionStade::effectuerSeance()
{
	//On récupère le débit necessaire pour calculer la lame d'eau
	double debit = seance.getDebit();

	//On calcule la lame d'eau = la hauteur dont la vanne doit se baisser pour laisser couleur un débit constant
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

//Formule : H² = Q / ( g . sqrt(2) . L . g . m) et L = 7 pour omniflots
double GestionStade::calculerLameEau()
{
	//En somme voilà ce qu'est la lame d'eau
	return reserve - omniflots.getHauteur();
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

