#include <iostream>
#include <string>
#include <fstream>
#include "Source.h"

void main(void)
{
	int m, n, NbTour, Iteration = 0;
	std::fstream Fichier;
	std::string Chemin = "C:/testSource.txt", Chemin2 = "C:/testFinal.txt", TableauJeux;
	Valeur_Tableau_s JeuVie;
	Valeur_Tableau_s* ptrTab = &JeuVie;
	
	JeuVie = Lire(Chemin);

	std::cout << JeuVie.Hauteur << "," << JeuVie.Largeur << std::endl;

	for (int i = 0; i < JeuVie.Hauteur; i++)
	{
		for (int j = 0; j < JeuVie.Largeur; j++)
		{
			std::cout << JeuVie.Vecteur_jeu[i][j];
			if (j == JeuVie.Hauteur) std::cout << std::endl;
		}
		if (i == JeuVie.Largeur) break;
	}

	std::cout << "Combien de tour de jeu voulez-vous? : ";
	std::cin >> NbTour;

	for (int h = 0; h < NbTour; h++)
	{
		system("cls");

		Iteration++;
		std::cout << Iteration << std::endl;
		JeuVie = Statut(JeuVie);
		Sleep(2);
		std::cout << std::endl;		
	}

	Ecrire(Chemin2, ptrTab, NbTour);
}
