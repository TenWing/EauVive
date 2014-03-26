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
    public:

        /**
        * le coefficient de marée
        */
        int coefficient;

        /**
         * Constructeur par défaut
         */
        GestionMaree();

        /**
         * accesseur au niveau de la mer, calcule son niveau à l'aide des capteurs et du coefficient
         * permet aussi de dire si la marée est montante ou descendante
         */
        double lireNiveauMaree();

        /**
        * Indique si la marée monte, sinon c'est qu'elle descend
        */
        bool estMontante();

        /**
        * Change la valeur du booléen indiquant si la marée monte
        */
        void changeMontante(bool montante);

    private:

        /**
        * le stade eau vive
        */
        GestionStade* stade;


        /**
         * le niveau de la mer calculé par les capteurs du système
         */
        double niveau;

        /**
        * indique si la marée est montante
        */
        bool montante;
};

#endif /* GESTIONMAREE_HPP_ */
