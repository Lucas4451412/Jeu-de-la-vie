#include <stdexcept>
#include <vector>
#include "Cellule.h"

// Indique que la classe RegleEvolution existe.
class RegleEvolution;

// Représente la grille du Jeu de la vie.
class Grille {
private:
    bool torique = false; // Définition de la grille torique à false car pas utile au début
    int largeur; // Nombre de colonnes.
    int hauteur; // Nombre de lignes.

    // Tableau de cellules accessible avec cellules[ligne][colonne].
    std::vector<std::vector<Cellule>> cellules;

    // Vérifie que la ligne et la colonne sont dans la grille.
    bool positionValide(int ligne, int colonne) const;

    // Compte les voisines vivantes autour de la cellule.
    int compterVoisinsVivants(int ligne, int colonne) const;

public:
    // Crée par défaut une grille d'une seule case.
    Grille();

    // Crée une grille de h lignes et l colonnes.
    Grille(int l, int h);

    
    void activerModeTorique(bool actif = true);

    int getlargeur() const;
    int gethauteur() const;

    // Donne accès à une cellule en lecture seule.
    const Cellule& getCellule(int ligne, int colonne) const;

    // Change l'état d'une cellule et renvoie true si l'opération réussit.
    bool definirEtatCellule(int ligne, int colonne, bool nouvelEtat);

    // Applique la règle à toute la grille pour passer à la génération suivante.
    void evoluer(const RegleEvolution& regle);
};
