/*
 * Vanne.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#ifndef VANNE_HPP_
#define VANNE_HPP_

#include "TypeVanne.hpp";

/**
 * Une vanne peut s'affaler et s'ouvrir pour laisser couler un débit d'eau
 */
class Vanne
{
	private:
		/**
		* la hauteur qu'atteint la vanne
		*/
		double hauteur;

		/**
		* le type de la vanne
		*/
		TypeVanne type;

	public:
		Vanne();
		virtual ~Vanne();
};

#endif /* VANNE_HPP_ */
