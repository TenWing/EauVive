/*
 * Vanne.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#ifndef VANNE_HPP_
#define VANNE_HPP_

#include "TypeVanne.hpp"

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

        /**
        * indique si la vanne est fermee
        */
        bool fermee;

        /**
        * indique si la vanne est affalée
        */
        bool affalee;

    public:

        /**
        * Constructeur par défaut
        */
        Vanne();

        /**
        * Constructeur paramêtré
        */
        Vanne(TypeVanne type, bool fermee);

        /**
        * Accesseur à la hauteur atteinte par la vanne
        */
        double getHauteur();

        /**
        * Demande à la vanne de s'ouvrir jusqu'à ce que la lame d'eau soit atteinte
        */
        void ouvrir(double lameEau);

        /**
        * Demande a la vanne de se fermer tout en suivant le niveau de la mer
        */
        void suivreMaree(double niveau);

        /**
        * affale cette vanne !
        */
        void affaler();

        /**
        * change le statut affalee de la vanne
        */
        void changeAffalee(bool affalee);

        /**
        * change le statut fermee de la vanne
        */
        void changeFermee(bool fermee);

        /**
        * change arbitrairement la hauteur de la vanne
        */
        void changeHauteur(double hauteur);

        /**
        * indique si la vanne est fermee
        */
        bool estFermee();

        /**
        * indique si la vanne est affalée
        */
        bool estAffalee();

        /**
        * ouvre cette vanne
        */
        void ouvre();

        /**
        * indique si la vanne est ouverte
        */
        bool estOuverte();
};

#endif /* VANNE_HPP_ */
