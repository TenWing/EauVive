/*
 * Seance.cpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#include "Seance.hpp"
#include "TypeProgramme.hpp"

Seance::Seance(TypeProgramme niveau) : programme(niveau)
{

}

double Seance::getDebit()
{
    switch(programme)
    {
        case TypeProgramme::Entrainement:
            return 4.6d;

        case TypeProgramme::Intermediaire:
            return 7.39d;

        case TypeProgramme::Confirme:
            return 10.36d;

        case TypeProgramme::Competition:
            return 13.84d;

        default:
            return 1.0d;
    }
}

TypeProgramme Seance::getProgramme()
{
    return programme;
}

