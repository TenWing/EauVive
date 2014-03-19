/*
 * Seance.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#ifndef SEANCE_HPP_
#define SEANCE_HPP_

#include "TypeProgramme.hpp"

/**
 * Une Seance indique le niveau de difficulté de la praticabilité de la rivière
 * permet de donner les informations essentielles pour la manipulation des vannes
 */
class Seance
{
		private :

		/**
		 * le niveau (de difficulté) associé à la séance
		 */
		TypeProgramme programme;

	public:

		/**
		 * Constructeur d'une séance (initialise le niveau a entraînement)
		 */
		Seance();

		/**
		 * Constructeur d'une séance avec le niveau d'entraînement
		 */
		Seance(TypeProgramme niveau);

		/**
		* calcule le débit d'eau de la rivière en fonction du programme
		*/
		double getDebit();
};

#endif /* SEANCE_HPP_ */
