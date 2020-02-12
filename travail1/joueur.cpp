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
	while (cartePlace == false)
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
	
	for(int compteurCarte = 0; compteurCarte <maxCartesAJouer;compteurCarte++)
	{	
		mainDuJoueur[compteurCarte] = NULL;
	}
}
void Joueur::AjouterDefaite(int nombreDefaites)
{
	nombreDefaites++;
}

void Joueur::AjouterVictoire(int nombreVitoires)
{
	nombreVictoires++;
}

int Joueur::GetDefaites()
{
	return nombreDefaites;
}
int Joueur::GetVictoires()
{
	return nombreVictoires;
}
string Joueur::GetNom()
{
	return nom;
}
Carte* Joueur::GetMain(int quelCarte)
{
	return mainDuJoueur[quelCarte];
}