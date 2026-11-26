#include "VueConsole.h"
#include "Grille.h"
#include "EtatCellule.h"
#include <iostream>

void VueConsole::afficher(const Grille& grille, int generation) const {
    const char* fondVivant = "\x1b[102m"; // Vert clair
    const char* fondMort   = "\x1b[100m"; // Gris foncé
    const char* reset      = "\x1b[0m";

    // Efface le terminal et replace le curseur en haut à gauche
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "Generation " << generation << '\n';

    for (int ligne = 0; ligne < grille.gethauteur(); ++ligne) {
        for (int colonne = 0; colonne < grille.getlargeur(); ++colonne) {
            TypeEtat type = grille.getCellule(ligne, colonne).getTypeEtat();

            switch (type) {
                case TypeEtat::Vivante:
                    std::cout << fondVivant << "  ";
                    break;
                case TypeEtat::Morte:
                default:
                    std::cout << fondMort << "  ";
                    break;
            }
        }
        std::cout << reset << '\n';
    }

    std::cout << std::flush;
}