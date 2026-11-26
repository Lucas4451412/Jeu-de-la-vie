#include <chrono>
#include <string>
#include <thread>
#include <iostream>
#include "lecture_fichier.h"
#include "RegleEvolution.h"

int main() {
    const std::string nomFichier = "Grille/grille.txt";
    const int nombreIterations = 50;
    const auto delai = std::chrono::milliseconds(500);

    // Charge la grille de départ depuis le fichier.
    Grille grille = lireGrille(nomFichier);

    // Relie les bords opposés pour le calcul des voisines.
    grille.activerModeTorique();

    // Utilise les règles du jeu de la vie de Conway.
    RegleConway regle;

    for (int i = 0; i < nombreIterations; i++) {
        // Attend une demi-seconde avant de calculer la génération suivante.
        std::this_thread::sleep_for(delai);
        grille.evoluer(regle);

        // Remplace le contenu de grille.txt par la nouvelle grille.
        ecrireGrille(nomFichier, grille);

        // Efface le terminal et replace le curseur en haut à gauche.
        std::cout << "\x1B[2J\x1B[H";

        // La boucle commence à 0, mais la première génération affichée est la 1.
        std::cout << "Generation " << i + 1 << '\n';
        afficherGrille(grille);
    }
}