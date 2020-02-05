#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{
private:
	Carte paquetCartes[52];
	Joueur joueur1;
	Joueur joueur2;
public:
		Donnees();
		void initialiserPaquetCarte();
};

