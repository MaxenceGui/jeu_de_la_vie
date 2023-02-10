#ifndef SOURCE_H
#include <string>
#include <vector>

struct Valeur_Tableau_s{
	int Hauteur;
	int Largeur;
	std::vector<std::vector<char>>  Vecteur_jeu;
};

void Sleep(int seconds);
Valeur_Tableau_s Statut(Valeur_Tableau_s);
void Ecrire(std::string, Valeur_Tableau_s*, int);
Valeur_Tableau_s Lire(std::string);
char AfficherResultat(int m, int n, Valeur_Tableau_s);

#define SOURCE_H
#endif // !SOURCE_H

