#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{
private:
public:
	Carte paquetCartes[52];
	Joueur joueur1;
	Joueur joueur2;
		Donnees();
		void initialiserPaquetCarte();
};

