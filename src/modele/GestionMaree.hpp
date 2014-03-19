/*
 * GestionMaree.hpp
 *
 *  Created on: 10 mars 2014
 *      Author: Tahiry
 */

#ifndef GESTIONMAREE_HPP_
#define GESTIONMAREE_HPP_

#include "GestionStade.hpp"

/**
 * Représente la marée et les informations extraites de celle-ci à l'aide
 * des capteurs
 */
class GestionMaree
{
<<<<<<< HEAD
	private:

		/**
		 * le niveau de la mer calculé par les capteurs du système
		 */
		double niveau;

		/**
		* le stade eau vive
		*/
		GestionStade stade;

	public:

		/**
		 * Constructeur par défaut
		 */
		GestionMaree();

		/**
		 * Destructeur de l'objet
		 */
		virtual ~GestionMaree();

		/**
		 * permet d'utiliser les capteurs pour vérifier le niveau de la mer
		 */
		void verifierNiveau();

		/**
		 * accesseur au niveau de la mer
		 */
		double lireNiveauMaree();
=======
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
>>>>>>> 5a2f1d4abe4a3470bed39bde6bc1d066545b724e
};

#endif /* GESTIONMAREE_HPP_ */
