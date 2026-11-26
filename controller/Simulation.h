#pragma once

#include <string>
#include "Grille.h"
#include "RegleEvolution.h"
#include "Vue.h"

class Simulation {
private:
    Grille grille;
    const RegleEvolution& regle;
    const Vue& vue;
    std::string fichierSauvegarde;
    int maxIterations;
    int delaiMs;

public:
    Simulation(Grille grilleInitiale,
               const RegleEvolution& regleEvolution,
               const Vue& vueAffichage,
               std::string cheminSauvegarde = "",
               int iterations = 50,
               int delaiMillisecondes = 500);

    void lancer();
};