#include "lecture_fichier.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

Grille lireGrille(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);

    if (!fichier) {
        throw std::runtime_error("Impossible d'ouvrir le fichier " + nomFichier);
    }

    // Le fichier indique le nombre de lignes, puis le nombre de colonnes.
    int hauteur;
    int largeur;

    if (!(fichier >> hauteur >> largeur) || hauteur <= 0 || largeur <= 0) {
        throw std::runtime_error("Les dimensions de la grille sont invalides.");
    }

    // Le constructeur attend la largeur, puis la hauteur.
    Grille grille(largeur, hauteur);

    // Les cellules gardent cette adresse après la fin de la fonction.
    static EtatVivante etatVivant;

    for (int ligne = 0; ligne < hauteur; ++ligne) {
        for (int colonne = 0; colonne < largeur; ++colonne) {
            int valeur;

            if (!(fichier >> valeur) || (valeur != 0 && valeur != 1)) {
                throw std::runtime_error("Il manque une case ou sa valeur est invalide.");
            }

            // Toutes les cellules sont mortes à la création de la grille.
            // Un 1 dans le fichier rend vivante la cellule correspondante.
            if (valeur == 1) {
                grille.definirEtatCellule(ligne, colonne, &etatVivant);
            }
        }
    }

    return grille;
}

void afficherGrille(const Grille& grille) {
    const char* fondVivant = "\x1b[102m"; // Vert clair
    const char* fondMort   = "\x1b[100m"; // Gris foncé

    for (int ligne = 0; ligne < grille.gethauteur(); ++ligne) {
        for (int colonne = 0; colonne < grille.getlargeur(); ++colonne) {
            bool vivante = grille.getCellule(ligne, colonne).estVivante();
            std::cout << (vivante ? fondVivant : fondMort) << "  ";
        }

        // Rétablit le fond normal avant de passer à la ligne suivante.
        std::cout << "\x1b[0m\n";
    }

    std::cout << std::flush;
}

void ecrireGrille(const std::string& nomFichier, const Grille& grille) {
    // Ouvre le fichier en remplaçant son ancien contenu.
    std::ofstream fichier(nomFichier, std::ios::trunc);

    if (!fichier) {
        throw std::runtime_error("Impossible d'ouvrir le fichier en ecriture : " + nomFichier);
    }

    // Écrit les dimensions dans l'ordre attendu par lireGrille().
    fichier << grille.gethauteur() << ' ' << grille.getlargeur() << '\n';

    // Écrit un 0 ou un 1 par cellule, avec des espaces entre les valeurs.
    for (int ligne = 0; ligne < grille.gethauteur(); ++ligne) {
        for (int colonne = 0; colonne < grille.getlargeur(); ++colonne) {
            fichier << grille.getCellule(ligne, colonne).estVivante() << ' ';
        }
        fichier << '\n';
    }

    fichier.close();
    if (!fichier) {
        throw std::runtime_error("Impossible d'enregistrer la grille : " + nomFichier);
    }
}
