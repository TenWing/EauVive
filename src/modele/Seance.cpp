/*
 * Seance.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "Seance.hpp"
#include "TypeProgramme.hpp"

//Initialise le programme a entrainement
Seance::Seance() : programme(TypeProgramme::ENTRAINEMENT)
{

}

Seance::Seance(TypeProgramme niveau) : programme(niveau)
{

}

double Seance::getDebit()
{
	switch(programme)
	{
		case ENTRAINEMENT :
			return 4.6f;

		case INTERMEDIAIRE :
			return 7.39f;

		case CONFIRME :
			return 10.36f;

		case COMPETITION :
			return 13.84f;

		default:
			return 1;
	}
}

TypeProgramme Seance::getProgramme()
{
	return programme;
}

