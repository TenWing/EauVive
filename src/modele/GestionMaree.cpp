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
    return (std::abs(6-Calendrier::heure) / 6 - 0.5) * (coefficient / 10.0) + 5.0;
}

bool GestionMaree::estMontante()
{
    return montante;
}

void GestionMaree::changeMontante(bool montante)
{
    this->montante = montante;
}
