/*
 * GestionMaree.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#ifndef CALENDRIER_HPP_
#define CALENDRIER_HPP_

class Calendrier
{
	public:

		/**
		* l'heure considérée par le système
		*/
		static int heure;

		/**
		* avance d'une heure dans le temps
		*/
		static void avancerTemps();
};

#endif /* CALENDRIER_HPP_ */