#include "joueur.h"



Joueur::Joueur()
{
	nom = "";
	nombreVictoires = 0;
	nombreDefaites = 0;
}

void Joueur::SetNomJoueur(string nomJoueur)
{
	nom = nomJoueur;
}

void Joueur::AjouterCarte(Carte* cartePige)
{
	bool cartePlace = false;
	int compteurCarte = 0;
	while (cartePlace == false /*&& compteurCarte <= maxCartesAJouer*/)
	{
		if (mainDuJoueur[compteurCarte] == NULL)
		{
			mainDuJoueur[compteurCarte] = cartePige;
			cartePlace = true;
		}
		compteurCarte += 1;
	}
}

void Joueur::ViderMainJoueur()
{
	bool mainVide = false;
	int compteurCarte = 0;
	while (mainVide == false)
	{
		if (mainDuJoueur[compteurCarte] == NULL)
		{
			mainVide = true;
		}
		else
		{
			mainDuJoueur[compteurCarte] = NULL;
		}
		compteurCarte += 1;
	}
}