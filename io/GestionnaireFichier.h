#pragma once

#include <string>
#include "Grille.h"

class GestionnaireFichier {
public:
    static Grille charger(const std::string& nomFichier);
    static void sauvegarder(const std::string& nomFichier, const Grille& grille);
};