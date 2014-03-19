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

Seance::~Seance()
{

}

