#ifndef CONSOLE_HPP_
#define CONSOLE_HPP_

#include "../modele/GestionStade.hpp"

/**
* l'affichage de l'application dans la console
*/
class Console
{
	public:
		/**
		* Constructeur par défaut
		*/
		Console();

		/**
		* lance l'appli
		*/
		void lancer();

	private:
		/**
		* le stade de l'application
		*/
		GestionStade stade;
};

#endif /* CONSOLE_HPP_ */