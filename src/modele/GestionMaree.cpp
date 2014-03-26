/*
 * GestionMaree.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */
#include <cmath>
#include "GestionMaree.hpp"
#include "Calendrier.hpp"

GestionMaree::GestionMaree() : coefficient(60), niveau(0), montante(false)
{

}

double GestionMaree::lireNiveauMaree()
{
    return (std::abs(6 - (Calendrier::heure%12) ) / 6 - 0.5d) * (coefficient / 10.0d) + 5.0d;
}

bool GestionMaree::estMontante()
{
    return (Calendrier::heure % 12) > 6;
}

void GestionMaree::changeMontante(bool montante)
{
    this->montante = montante;
}
