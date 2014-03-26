/*
 * GestionStade.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "GestionStade.hpp"
#include "GestionMaree.hpp"
#include "Calendrier.hpp"
#include <tgmath.h>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

//par défaut on indique que la vanne omniflots est affalée et que la vanne stockVide est fermée
//rien dans la reserve, séance d'entraînement
GestionStade::GestionStade() : omniflots(TypeVanne::OMNIFLOTS, false), stockVide(TypeVanne::STOCKVIDE, true),
    seance(TypeProgramme::Competition), maree(), reserve(0), intervention(false), ngf(5)
{
    //On suppose qu'on démarre à 
    Calendrier::heure = 12;
    reserve = ngf;
}


void GestionStade::automatique()
{
    //On regarde le niveau de la mer
    double niveau = maree.lireNiveauMaree();

    //Si la marée monte et que la marée peut remplir la reserve
    if(maree.estMontante() && niveau > ngf)
    {
        //Si la vanne est fermee
        if(omniflots.estFermee())
        {  
            //Alors tant pis on est con on attend que l'eau descende puis remonte en faisant attention a remplir 
            //la reserve pour pouvoir faire une scéance

            //On oublie pas d'affaler la vanne
            omniflots.affaler();

            while(niveau > ngf)
            { 
                //On continue d'attendre
                Calendrier::avancerTemps();
                niveau = maree.lireNiveauMaree();
            }

            reserve = ngf;

            //On continue d'attendre
            while(niveau <= ngf)
            {                
                //On continue d'attendre
                Calendrier::avancerTemps();
                niveau = maree.lireNiveauMaree();
            }

            //Arrivé ici on voit que la marée monte et peut remplir le stade jusqu'a la séance !
            remplirReserve();

        }
        //Sinon c'est cool !
        else
        {             
            //On demande a la vanne omniflots de se fermer progressivement pour retenir l'eau
            remplirReserve();
        }
    }   
    //Si la marée monte et que le niveau de la mer est bas
    else if(maree.estMontante() && niveau <= ngf)
    {
        //Si on est con et on a fermée la vanne
        if(omniflots.estFermee())
            //vite on l'affale !!
            omniflots.affaler();

        //On ne fait rien on attend que la marée puisse remplir le stade
        while(niveau <= ngf)
        {            
            //On avance
            Calendrier::avancerTemps();
            niveau = maree.lireNiveauMaree();
        }

        //On remplit la reserve
        remplirReserve();
    }
    //Si la marée descend et qu'elle est au dessus du niveau du stade
    else if(!maree.estMontante() && niveau > ngf)
    {        
        //Si la vanne omniflots est fermée et qu'il y a de l'eau dans la réserve
        if(omniflots.estFermee() && reserve > ngf)
        {            
            //On attend que le niveau soit en dessous de ngf pour commencer une séance
            while(niveau > ngf)
            {                
                //On avance
                Calendrier::avancerTemps();
                niveau = maree.lireNiveauMaree();
            }
        }
        //Si la vanne omniflots est fermée mais qu'il n'y a pas d'eau dans la réserve
        else if(omniflots.estFermee() && reserve <= ngf)
        {            
            //On affale les deux vannes !! puis on attend que la reserve se remplisse pour pouvoir refaire une séance
            omniflots.affaler();
            stockVide.affaler();

            while(!maree.estMontante())
            {                
                Calendrier::avancerTemps();
            }

            //On lit le niveau de la mer au plus bas
            niveau = maree.lireNiveauMaree();

            //On attend qu'elle puisse remplir la réserve
            while(niveau <= ngf)
            {
                Calendrier::avancerTemps();
            }

            remplirReserve();
        }
        //si la vanne est affalée et que la marée descend et peut remplir le stade
        else if(omniflots.estAffalee())
        {
            //On prend pas de risque on attend que la mer descende puis remplisse la reserve pour commencer une seance
            while(!maree.estMontante())
            {                
                Calendrier::avancerTemps();                
            }

            //On lit le niveau de la maree
            niveau = maree.lireNiveauMaree();

            while(niveau <= ngf)
            {
                Calendrier::avancerTemps();
                niveau = maree.lireNiveauMaree();
            }

            remplirReserve();
        }
    }
    //Si la marée descend mais que la marée est basse
    else if(!maree.estMontante() && niveau <= ngf)
    {
        //Si on est con et on a fermée la vanne
        if(omniflots.estFermee())
            //vite on l'affale !!
            omniflots.affaler();

        //On va attendre ensuite que l'eau monte toussa toussa pour refaire une séance
        niveau = maree.lireNiveauMaree();

        //On attend que l'eau puisse remplir la reserve
        while(niveau <= ngf)
        {
            Calendrier::avancerTemps();
            niveau = maree.lireNiveauMaree();
        }

        remplirReserve();
    }

    //Ici on va commencer la séance sachant que :
    //Au debut d'une seance la hauteur de la vanne est la même que la reserve
    //la marée doit descendre et être  <= ngf
    //Mais pour ça il faut attendre marée basse

    niveau = maree.lireNiveauMaree();

    while(!maree.estMontante() && niveau > ngf)
    {
        niveau = maree.lireNiveauMaree();
        Calendrier::avancerTemps();
    }

    //On décrit la situation avant de commencer

    std::cout << "Statut au demarrage : " << description() << std::endl;

    commencerSeance();
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

    //On avance dans le temps
    Calendrier::avancerTemps();
}

void GestionStade::commencerSeance()
{   
    //On dit que la vanne s'ouvre
    omniflots.ouvre();

	//tant que la séance n'est pas terminée
	while(!verifierFinSeance())
	{         
		//On effectue la séance
		effectuerSeance();

        //On affiche l'état de la séance
        std::cout << description() << std::endl;
	}

    //On est arrivé à la fin de la séance
    //On demande l'intervention d'un humain
    intervention = true;   
}

void GestionStade::finSeance()
{
    
    //On affale les vannes
    omniflots.affaler();

    //On affale aussi la vanne stockVide
    stockVide.affaler();

    //la reserve se vide
    reserve = maree.lireNiveauMaree();

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

void GestionStade::remplirReserve()
{
    double niveau = maree.lireNiveauMaree();

    while(niveau > ngf && maree.estMontante())
    {       
        //On avance dans le temps
        Calendrier::avancerTemps();

        //On réactualise le niveau
        niveau = maree.lireNiveauMaree();    
   
        //On demande a la vanne de suivre le niveau
        omniflots.suivreMaree(niveau);

        //On remplit la reserve
        reserve = niveau;        
    }

    //la marée descend ce qui stoppe tout

    //On oublie pas quand tout est fini de bien fermer la vanne
    omniflots.changeHauteur(reserve);
    omniflots.changeFermee(true);
    omniflots.changeAffalee(false);
}

std::string GestionStade::description()
{
    std::stringstream str;
    str << "Niveau de la mer : ";
    str << maree.lireNiveauMaree();
    str << "\n";
    str << "Niveau de la reserve ";
    str << reserve;
    str << "\n";
    str << "Vanne omniflots ? ";
    if(omniflots.estFermee())
        str << "FERMEE ! ";
    else if(omniflots.estAffalee())
        str << "AFFALEE ";
    else if(omniflots.estOuverte())
        str << "OUVERTE";
    str << "\n";

    str << "Vanne stockVide ? ";
    if(stockVide.estFermee())
        str << "FERMEE ! ";
    else if(stockVide.estAffalee())
        str << "AFFALEE ";
    else if(stockVide.estOuverte())
        str << "OUVERTE";
    str << "\n";

    str << "Il est actuellement : ";
    str << Calendrier::heure;
    str << "heure(s)";
    str << "\n";

    return str.str();
}

bool GestionStade::requiertIntervention()
{
    return intervention;
}

void GestionStade::changeSeance(Seance seance)
{
    this->seance = seance;
}

void GestionStade::changeMaree(GestionMaree maree)
{
    this->maree = maree;
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

