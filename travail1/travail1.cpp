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
void MelangerPaquet();
void Distribution();
int AfficherTotaux(Joueur* joueurSelectionnee);
void TerminerPartie(int totalJoueur1, int totalJoueur2);

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
	cout << "\n" << leJeu.joueur1.GetNom() << " a gagner " << leJeu.joueur1.GetVictoires() << " et a perdu " << leJeu.joueur1.GetDefaites() << "\n";
	cout << "\n" << leJeu.joueur2.GetNom() << " a gagner " << leJeu.joueur2.GetVictoires() << " et a perdu " << leJeu.joueur2.GetDefaites() << "\n";
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
	cout << "Combien de cartes voulez-vous distribue(max 26)?\n";
	cin >> distribution;
	if (distribution > maxCartesAJouer)
	{
		distribution = maxCartesAJouer;
		cout << "Vous avez dépasser le max!";
	}
	cout << "Chaque joueur aura donc " << distribution << " cartes!";
	for (int cpt = 0; cpt < distribution; cpt++)
	{
		leJeu.joueur1.AjouterCarte(&leJeu.paquetCartes[cpt]);
		leJeu.joueur2.AjouterCarte(&leJeu.paquetCartes[maxCartes-1 - cpt]);
	}
}

int AfficherTotaux(Joueur* joueurSelectionnee)
{
	cout <<"\nLes cartes de "<< joueurSelectionnee->GetNom()<<" sont :";
	int cpt = 0;
	int totalJoueur = 0;
	Carte* afficherCarte;
	while (joueurSelectionnee->GetMain(cpt) == NULL)
	{
		afficherCarte = joueurSelectionnee->GetMain(cpt);
		cout << "\nle " << afficherCarte->GetValeur() << " de " << afficherCarte->GetAtout();
		totalJoueur += afficherCarte->GetValeur();
		cpt += 1;
	}
	cout << "\nTotal de pts: " << totalJoueur;
	return totalJoueur;
}

void TerminerPartie(int totalJoueur1, int totalJoueur2)
{
	if (totalJoueur1 > totalJoueur2)
	{
		cout <<"\n"<< leJeu.joueur1.GetNom() << " à gagne avec " << totalJoueur1 << " pts!";
		leJeu.joueur1.AjouterVictoire(leJeu.joueur1.GetVictoires());
		leJeu.joueur2.AjouterDefaite(leJeu.joueur2.GetDefaites());

	}
	else if (totalJoueur1 > totalJoueur2)
	{
		cout << "\n" << leJeu.joueur2.GetNom() << " à gagne avec " << totalJoueur2 << " pts!";
		leJeu.joueur2.AjouterVictoire(leJeu.joueur2.GetVictoires());
		leJeu.joueur1.AjouterDefaite(leJeu.joueur1.GetDefaites());
	}
	else
	{
		cout << "\nLa partie est nule avec un total de " << totalJoueur1 << " pts...";

	}
	leJeu.joueur1.ViderMainJoueur();
	leJeu.joueur2.ViderMainJoueur();
}

void Jouer() 
{
	MelangerPaquet();
	Distribution();
	int totalJoueur1 = AfficherTotaux(&leJeu.joueur1);
	int totalJoueur2 = AfficherTotaux(&leJeu.joueur2);
	TerminerPartie(totalJoueur1, totalJoueur2);	
}

void InitialiserJoueurs()
{
	string nom;
	cout << "Quel est le nom du joueur 1?\n";
	cin >> nom;
	leJeu.joueur1.SetNomJoueur(nom);
	cout << "\nQuel est le nom du joueur 2?\n";
	cin >> nom;
	leJeu.joueur2.SetNomJoueur(nom);
}
