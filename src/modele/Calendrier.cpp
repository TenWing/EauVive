#include "Calendrier.hpp"

int Calendrier::heure = 0;

void Calendrier::avancerTemps()
{
	Calendrier::heure++;

	if(Calendrier::heure > 23)
		Calendrier::heure = 0;
}