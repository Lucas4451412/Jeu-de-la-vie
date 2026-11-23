#include "Grille.h"
#include "RegleEvolution.h"
#include <stdexcept>


Grille::Grille() : Grille(1, 1) {}

Grille::Grille(int l, int h) : largeur(l), hauteur(h) {
        if (l <= 0 || h <= 0) {
            throw std::invalid_argument("Les dimensions doivent être positives.");
        }

        // Remplit la grille avec h lignes de l cellules chacune.
        cellules.resize(h, std::vector<Cellule>(l));
}

void Grille::activerModeTorique(bool actif) {
        torique = actif;
}

// Vérifie que les coordonnées correspondent à une case de la grille.
bool Grille::positionValide(int ligne, int colonne) const {
    if (ligne >= 0 && ligne < hauteur
        && colonne >= 0 && colonne < largeur) {
        return true;
    }

    return false;
}

int Grille::compterVoisinsVivants(int ligne, int colonne) const {
    int voisinsVivants = 0;

    int haut = ligne - 1;
    int bas = ligne + 1;
    int gauche = colonne - 1;
    int droite = colonne + 1;

    if (torique) {
        // Ramène chaque indice qui dépasse sur le bord opposé.
        haut   = (haut + hauteur) % hauteur;
        bas    = bas % hauteur;
        gauche = (gauche + largeur) % largeur;
        droite = droite % largeur;

        // Sur une petite grille, -1 indique une direction à ignorer pour ne pas compter 2 fois la même voisine
        if (hauteur == 1) {
            haut = -1;
        }
        if (hauteur <= 2) {
            bas = -1;
        }
        if (largeur == 1) {
            gauche = -1;
        }
        if (largeur <= 2) {
            droite = -1;
        }
    }

    // Les trois voisines du haut.
    if (positionValide(haut, gauche)) {
        voisinsVivants += cellules[haut][gauche].estVivante();
    }
    if (positionValide(haut, colonne)) {
        voisinsVivants += cellules[haut][colonne].estVivante();
    }
    if (positionValide(haut, droite)) {
        voisinsVivants += cellules[haut][droite].estVivante();
    }

    // Les deux voisines sur la même ligne.
    if (positionValide(ligne, gauche)) {
        voisinsVivants += cellules[ligne][gauche].estVivante();
    }
    if (positionValide(ligne, droite)) {
        voisinsVivants += cellules[ligne][droite].estVivante();
    }

    // Les trois voisines du bas.
    if (positionValide(bas, gauche)) {
        voisinsVivants += cellules[bas][gauche].estVivante();
    }
    if (positionValide(bas, colonne)) {
        voisinsVivants += cellules[bas][colonne].estVivante();
    }
    if (positionValide(bas, droite)) {
        voisinsVivants += cellules[bas][droite].estVivante();
    }

    return voisinsVivants;
}

int Grille::getlargeur() const {
    return this->largeur;
}

int Grille::gethauteur() const {
    return this->hauteur;
}

// Donne accès à une cellule en lecture seule.
const Cellule& Grille::getCellule(int ligne, int colonne) const {
    if (!positionValide(ligne, colonne)) {
        throw std::out_of_range("Position en dehors de la grille");
    }

    return cellules[ligne][colonne];
}

// Change l'état de la cellule et indique si l'opération a réussi.
bool Grille::definirEtatCellule(int ligne, int colonne, EtatCellule* nouvelEtat) {
    // Refuse les coordonnées hors grille ou un pointeur nul.
    if (!positionValide(ligne, colonne) || nouvelEtat == nullptr) {
        return false;
    }

    cellules[ligne][colonne].definirEtat(nouvelEtat);
    return true;
}


void Grille::evoluer(const RegleEvolution& regle) {
    std::vector<std::vector<bool>> etatsSuivants(
        hauteur, std::vector<bool>(largeur)
    );

    // 1. Calculer les prochains états à partir de la grille actuelle.
    for (int ligne = 0; ligne < hauteur; ++ligne) {
        for (int colonne = 0; colonne < largeur; colonne += 1) {
            bool vivante = cellules[ligne][colonne].estVivante();
            int voisinsVivants = compterVoisinsVivants(ligne, colonne);

            etatsSuivants[ligne][colonne] = regle.determinerEtatSuivant(vivante, voisinsVivants);
        }
    }

    static EtatVivante etatVivant;
    static EtatMorte etatMort;

    // 2. Appliquer les nouveaux états une fois tous les calculs terminés.
    for (int ligne = 0; ligne < hauteur; ligne += 1) {
        for (int colonne = 0; colonne < largeur; colonne += 1) {
            if (etatsSuivants[ligne][colonne]) {
                cellules[ligne][colonne].definirEtat(&etatVivant);
            } 
            else {
                cellules[ligne][colonne].definirEtat(&etatMort);
            }
        }
    }
}