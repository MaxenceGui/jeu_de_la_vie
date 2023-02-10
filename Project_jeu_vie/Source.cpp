#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <tuple>
#include <vector>
#include "Source.h"

void Sleep(int seconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
}
Valeur_Tableau_s Statut(Valeur_Tableau_s Grille)
{
	std::vector<std::vector<char>> NouveauTableau(Grille.Hauteur, std::vector<char>(Grille.Largeur));

	for (int i = 0; i < Grille.Hauteur; i++)
	{
		for (int j = 0; j < Grille.Largeur; j++)
		{
			NouveauTableau[i][j] = AfficherResultat(i,j,Grille);			
		}
	}

	for (int k = 0; k < Grille.Hauteur; k++)
	{
		for (int l = 0; l < Grille.Largeur; l++)
		{ 
			Grille.Vecteur_jeu[k][l] = NouveauTableau[k][l];
			std::cout << Grille.Vecteur_jeu[k][l];
		}
		std::cout << std::endl;
	}
	return Grille;
}
char AfficherResultat(int posi, int posj, Valeur_Tableau_s Tab)
{
	int Compteur = 0;
	//Tableau modifier à utiliser ici et à retourner dans l'autre fonction

	for (int i = posi-1; i <= posi+1; i++)
	{
		if (i >= 0 && i < Tab.Hauteur)
		{
			for (int j = posj-1; j <= posj + 1; j++)
			{
				if (j >= 0 && j < Tab.Largeur)
				{
					if (i != posi || j != posj)
					{
					if (Tab.Vecteur_jeu[i][j] == '#') Compteur++;
					}
				}
			}
		}
	}
	if (Tab.Vecteur_jeu[posi][posj] == '#')
	{
		if (Compteur == 2 || Compteur == 3) return '#';
		else return '*';
	}
	else
	{
	if (Compteur == 3) return  '#';
	else return '*';
	}
}


void Ecrire(std::string Chemin, Valeur_Tableau_s* Message, int Iteration)

{
	std::fstream Fichier;
	std::string Chaine = "";
	std::vector<std::vector<char>> NouveauTableau(Message->Hauteur, std::vector<char>(Message->Largeur));

	Fichier.open(Chemin, std::ios::out);
	if (Fichier.fail())
	{
		Chaine = "Le fichier n'a pas pu ouvrir. Fin du programme";
		exit(EXIT_FAILURE);
	}

	Fichier << Iteration << std::endl;
	for (int i = 0; i < Message->Hauteur; i++)
	{
		for (int j = 0; j < Message->Largeur; j++)
		{
			Fichier << Message->Vecteur_jeu[i][j];
		}
		Fichier << std::endl;
	}
	
	Fichier.close();
}
Valeur_Tableau_s Lire(std::string Chemin)
{
	std::fstream Fichier;
	std::string Chaine = "", ligne, Colonne;
	Valeur_Tableau_s Tableau_jeu;
	Tableau_jeu.Hauteur, Tableau_jeu.Largeur;
	
	Fichier.open(Chemin, std::ios::in);

	if (Fichier.fail())
	{
		Chaine = "Le fichier n'a pas pu ouvrir. Fin du programme";
		exit(EXIT_FAILURE);
	}

	if (Fichier)
	{
		getline(Fichier, ligne, ',');
		getline(Fichier, Colonne);

		Tableau_jeu.Hauteur = std::stoi(ligne);
		Tableau_jeu.Largeur = std::stoi(Colonne);

		std::vector<std::vector<char>> TableauVecteur(Tableau_jeu.Hauteur, std::vector < char>(Tableau_jeu.Largeur));
		for (int i = 0; i < Tableau_jeu.Hauteur; i++)
		{
			getline(Fichier, Chaine);
			for (int j = 0; j < Tableau_jeu.Largeur; j++)
			{
				TableauVecteur[i][j] = Chaine.at(j);
			}
		}
		Tableau_jeu.Vecteur_jeu = TableauVecteur;
		
		return Tableau_jeu;
	}
	Fichier.close();
}
