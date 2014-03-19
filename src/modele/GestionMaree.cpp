/*
 * GestionMaree.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */
#include <cmath>
#include "GestionMaree.hpp"

GestionMaree::GestionMaree()
{
    coefficient = 60;
    heure = 11;
}

GestionMaree::~GestionMaree()
{
	
}

double GestionMaree::lireNiveauMaree()
{
    heure = (heure + 1) % 12;
    
    return (std::abs(6-heure) / 6 - 0.5) * (coefficient / 10.0) + 5.0;
}

