/*
 * GestionMaree.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tahiry
 */

#ifndef GESTIONMAREE_HPP_
#define GESTIONMAREE_HPP_

/**
 * Représente la marée et les informations extraites de celle-ci à l'aide
 * des capteurs
 */
class GestionMaree
{
    private:

        /**
         * le niveau de la mer calculé par les capteurs du système
         */
        double niveau;
        
        int heure;

    public:
    
        int coefficient;

        /**
         * Constructeur par défaut
         */
        GestionMaree();

        /**
         * permet d'utiliser les capteurs pour vérifier le niveau de la mer
         */
        void verifierNiveau();

        /**
         * accesseur au niveau de la mer
         */
        double lireNiveauMaree();
};

#endif /* GESTIONMAREE_HPP_ */
