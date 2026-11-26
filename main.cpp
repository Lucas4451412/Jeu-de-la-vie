#include <iostream>
#include <string>
#include "GestionnaireFichier.h"
#include "RegleEvolution.h"
#include "VueConsole.h"
#include "Simulation.h"

int main() {
    try {
        const std::string nomFichier = "data/grille.txt";

        // 1. Préparation du Modèle
        Grille grille = GestionnaireFichier::charger(nomFichier);
        grille.activerModeTorique();
        RegleConway regle;

        // 2. Choix de la Vue
        VueConsole vue;
        //VueSFML vue;

        // 3. Lancement via le Contrôleur
        Simulation simulation(std::move(grille), regle, vue, nomFichier, 50, 500);
        simulation.lancer();

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << '\n';
        return 1;
    }

    return 0;
}