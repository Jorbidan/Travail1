#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;
class Joueur
{
private:
	string nom;
	int nombreVictoires;
	int nombreDefaites;
	Carte* mainDuJoueur[maxCartesAJouer];
public:
	Joueur();
	void SetNomJoueur(string nomJoueur);
	void AjouterCarte(Carte* cartePige);
	void ViderMainJoueur();
	void AjouterDefaite(int nombreDefaites);
	void AjouterVictoire(int nombreVictoires);
};
#endif