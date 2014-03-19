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
 * Représente l'objet stade, cntenant toutes les structures pouvant
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

	public:

		/**
		* Constructeur par défaut
		*/
		GestionStade();

		/**
		* commence la séance actuelle
		*/
		void commencerSeance();

		/**
		*	Interrompt la seance jouée
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
		boolean verifierFinSeance();
};

#endif /* GESTIONSTADE_HPP_ */
