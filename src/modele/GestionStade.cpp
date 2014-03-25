/*
 * GestionStade.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "GestionStade.hpp"
#include "Calendrier.hpp"
#include <tgmath.h>
#include <cmath>
#include <iostream>

GestionStade::GestionStade() : ngf(5)
{
    Calendrier::heure = 11;
}


void GestionStade::automatique()
{
    //On regarde le niveau de la mer
    double niveauDepart = maree.lireNiveauMaree();

    //On est obligé d'avancer dans le temps pour savoir si la marée monte ou descend
    Calendrier::avancerTemps();

    //On relit le niveau de la marée
    double niveau = maree.lireNiveauMaree();

    //En fonction des variations on indique si la marée monte ou descend
    if(niveauDepart > niveau)
        maree.changeMontante(false);
    else
        maree.changeMontante(true);

    //Si la marée monte et que la marée peut remplir la reserve
    if(maree.estMontante() && niveau >= ngf)
    {
        //On demande a la vanne de se fermer progressivement en suivant le niveau de la mer
        //TODO
    }   
    //Si la marée monte et que le niveau de la mer est bas
    else if(maree.estMontante() && niveau <= ngf)
    {
        //On ne fait rien on attend que la marée puisse remplir le stade
    }
    //Si la marée descend et qu'elle est au dessus du niveau de la reserve
    else if(!maree.estMontante() && niveau >= ngf)
    {
        //Si la vanne omniflots est fermée
        if(omniflots.estFermee())
        {
            
        }
    }

}

bool GestionStade::verifierFinSeance()
{
    double niveauMaree = maree.lireNiveauMaree();

	//si le niveau de la mer est au dessus du 0NGF+ ici 5m alors on arrête la séance
	if(niveauMaree >= ngf)
		return true;

    //Si le niveau de la réserve est épuisé alors on arrête la séance
    if(reserve <= ngf)
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
        case TypeProgramme::Entrainement:
            return 0.3d;

        case TypeProgramme::Intermediaire:
            return 0.38d;

        case TypeProgramme::Confirme:
            return 0.45d;

        case TypeProgramme::Competition:
            return 0.52d;

        default:
            return 1.0d;
    }
}

double GestionStade::calculeM(double Hauteur, double Largeur)
{
    return 0.525d * (1 + 1 / ((1000*Hauteur) + 1.6d) ) * (1 + 0.55d * (pow(Hauteur,2) / pow(Hauteur+Largeur,2)));
}

double GestionStade::deduitQdeH(double H)
{
    double m = calculeM(H, 7);

    double q =  (m * pow(H,2) * sqrt(2) * 9.81d * 7);

    return q;
}

