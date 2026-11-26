#include "GestionnaireFichier.h"
#include "EtatCellule.h"
#include <fstream>
#include <stdexcept>

Grille GestionnaireFichier::charger(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }

    int hauteur = 0;
    int largeur = 0;
    if (!(fichier >> hauteur >> largeur) || hauteur <= 0 || largeur <= 0) {
        throw std::runtime_error("Les dimensions de la grille sont invalides.");
    }

    Grille grille(largeur, hauteur);

    for (int ligne = 0; ligne < hauteur; ++ligne) {
        for (int colonne = 0; colonne < largeur; ++colonne) {
            int valeur = 0;
            if (!(fichier >> valeur)) {
                throw std::runtime_error("Il manque une case dans le fichier.");
            }

            switch (valeur) {
                case 0:
                    grille.definirEtatCellule(ligne, colonne, EtatMorte::instance());
                    break;
                case 1:
                    grille.definirEtatCellule(ligne, colonne, EtatVivante::instance());
                    break;
                default:
                    throw std::runtime_error("Valeur de cellule invalide dans le fichier.");
            }
        }
    }

    return grille;
}

void GestionnaireFichier::sauvegarder(const std::string& nomFichier, const Grille& grille) {
    std::ofstream fichier(nomFichier, std::ios::trunc);
    if (!fichier) {
        throw std::runtime_error("Impossible d'ouvrir le fichier en ecriture : " + nomFichier);
    }

    fichier << grille.gethauteur() << ' ' << grille.getlargeur() << '\n';

    for (int ligne = 0; ligne < grille.gethauteur(); ++ligne) {
        for (int colonne = 0; colonne < grille.getlargeur(); ++colonne) {
            TypeEtat type = grille.getCellule(ligne, colonne).getTypeEtat();
            int code = 0;

            switch (type) {
                case TypeEtat::Morte:   code = 0; break;
                case TypeEtat::Vivante: code = 1; break;
            }

            fichier << code << ' ';
        }
        fichier << '\n';
    }

    if (!fichier) {
        throw std::runtime_error("Erreur lors de l'enregistrement de la grille : " + nomFichier);
    }
}