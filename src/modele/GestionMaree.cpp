/*
 * GestionMaree.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */
#include <cmath>
#include "GestionMaree.hpp"
#include "Calendrier.hpp"

GestionMaree::GestionMaree() : coefficient(60), niveau(0)
{

}

double GestionMaree::lireNiveauMaree()
{
    //heure = (heure + 1) % 12;
    int heure = Calendrier::heure;
    
    return (std::abs(6-heure) / 6 - 0.5) * (coefficient / 10.0) + 5.0;
}

