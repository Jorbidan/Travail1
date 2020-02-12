#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;

void InitialiserJoueurs();
void Jouer();

int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
}

void MelangerPaquet()
{
	int carte1;
	int carte2;
	Carte carteTempo;
	for (int cpt = 0; cpt < 10000; cpt++)
	{
		carte1 = (rand() % 51);
		carte2 = (rand() % 51);
		carteTempo = leJeu.paquetCartes[carte1];
		leJeu.paquetCartes[carte1] = leJeu.paquetCartes[carte2];
		leJeu.paquetCartes[carte2] = carteTempo;
	}
}

void Distribution()
{
	int distribution;
	cout << "combien de cartes voulez-vous distribué(max 26)?";
	cin >> distribution;
	if (distribution > maxCartesAJouer)
	{
		distribution = maxCartesAJouer;
	}
	for (int cpt = 0; cpt < distribution; cpt++)
	{
		leJeu.joueur1.AjouterCarte(&leJeu.paquetCartes[cpt]);
		leJeu.joueur2.AjouterCarte(&leJeu.paquetCartes[maxCartes-1 - cpt]);
	}
}

void Jouer() 
{
	MelangerPaquet();
	Distribution();
	
}

void InitialiserJoueurs()
{
	string nom;
	cout << "\nQuel est le nom du joueur 1?\n";
	cin >> nom;
	leJeu.joueur1.SetNomJoueur(nom);
	cout << "\nQuel est le nom du joueur 2?\n";
	cin >> nom;
	leJeu.joueur2.SetNomJoueur(nom);
}
