/*
 * GestionMaree.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tendry
 */

#ifndef GESTIONMAREE_HPP_
#define GESTIONMAREE_HPP_

class GestionStade;

/**
 * Représente la marée et les informations extraites de celle-ci à l'aide
 * des capteurs
 * 0 NGF = 5m !!!!!
 */
class GestionMaree
{
    private:

        /**
         * le niveau de la mer calculé par les capteurs du système
         */
        double niveau;

        /**
        * le stade eau vive
        */
        GestionStade* stade;

        /**
        * l'heure lue
        */
        int heure;

    public:

        /**
        * le coefficient de maréé
        */
        int coefficient;

        /**
         * Constructeur par défaut
         */
        GestionMaree();

        /**
         * accesseur au niveau de la mer, calcule son niveau à l'aide des capteurs et du coefficient
         */
        double lireNiveauMaree();
};

#endif /* GESTIONMAREE_HPP_ */
