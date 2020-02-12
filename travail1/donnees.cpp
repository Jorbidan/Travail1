#include "donnees.h"



Donnees::Donnees()
{
	initialiserPaquetCarte();
}

void Donnees::initialiserPaquetCarte()
{
	int nombreCarteTotal = 0;
	for (int atoutNum = 0; atoutNum <= 3; atoutNum++)
	{
		string atout;
		switch (atoutNum)
		{
		case 0:
			atout = "pique"; break;
		case 1:
			atout = "coeur"; break;
		case 2:
			atout = "trefle"; break;
		case 3:
			atout = "carreau"; break;
		}
		for (int compteurCarte = 1; compteurCarte <= 13; compteurCarte++)
		{
			paquetCartes[nombreCarteTotal].InitialiserCarte(compteurCarte, atout);
			nombreCarteTotal++;
		}
	}
}
