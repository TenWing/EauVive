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
	int heure = Calendrier::heure%12;

    return (std::abs(6-heure) / 6 - 0.5d) * (coefficient / 10.0d) + 5.0d;
}

bool GestionMaree::estMontante()
{
    return montante;
}

void GestionMaree::changeMontante(bool montante)
{
    this->montante = montante;
}
