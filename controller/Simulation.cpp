#include "Simulation.h"
#include "GestionnaireFichier.h"
#include <chrono>
#include <thread>
#include <utility>

Simulation::Simulation(Grille grilleInitiale,
                       const RegleEvolution& regleEvolution,
                       const Vue& vueAffichage,
                       std::string cheminSauvegarde,
                       int iterations,
                       int delaiMillisecondes)
    : grille(std::move(grilleInitiale)),
      regle(regleEvolution),
      vue(vueAffichage),
      fichierSauvegarde(std::move(cheminSauvegarde)),
      maxIterations(iterations),
      delaiMs(delaiMillisecondes) {}

void Simulation::lancer() {
    // Affiche l'état initial (Génération 0)
    vue.afficher(grille, 0);

    for (int i = 1; i <= maxIterations; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delaiMs));

        grille.evoluer(regle);

        if (!fichierSauvegarde.empty()) {
            GestionnaireFichier::sauvegarder(fichierSauvegarde, grille);
        }

        vue.afficher(grille, i);
    }
}