/*
 * GestionStade.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#ifndef GESTIONSTADE_HPP_
#define GESTIONSTADE_HPP_

#include "Seance.hpp"
#include "Vanne.hpp"
#include "GestionMaree.hpp"

/**
 * Représente l'objet stade, contenant toutes les structures pouvant
 * mettre en place la rivière artificielle
 */
class GestionStade
{
	private:

		/**
		* la vanne omniflots
		*/
		Vanne omniflots;
		
		/**
		* la vanne sotckvide
		*/
		Vanne stockVide;

		/**
		* La seance associée
		*/
		Seance seance;

		/**
		* la marée qui interéagit avec le stade
		*/
		GestionMaree maree;

		/**
		* le niveau de la résèrve
		*/
		double reserve;

		/**
		* calcule la variable m nécessaire au calcul de la lame d'eau
		*/
		double calculeM(double hauteur, double largeur);

	public:

		/**
		* le niveau 0 par rapport au stade
		*/
		int ngf;

		/**
		* Constructeur par défaut
		*/
		GestionStade();

		/**
		* commence la séance actuelle
		*/
		void commencerSeance();

		/**
		* Interrompt la seance jouée
		*/
		void interompreSeance();

		/**
		* le traitement effectuer au cours d'une seance
		*/
		void effectuerSeance();

		/**
		* vérifie si la séance est terminée 
		* et renvoie un booléen répondant a la question
		*/
		bool verifierFinSeance();

		/**
		* calcule la lame d'eau //la lame d'eau est la différence entre le niveau de la résèrve et la hauteur qu'atteint la vanne
		*/
		double calculerLameEau();

		/**
		* travail effectué par l'application en mode automatique
		*/
		void automatique();

		/**
		* déduit Q de H
		*/
		double deduitQdeH(double H);
};

#endif /* GESTIONSTADE_HPP_ */
