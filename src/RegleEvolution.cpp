#include "RegleEvolution.h"

bool RegleConway::determinerEtatSuivant(bool vivante, int voisinsVivants) const {
    if (vivante) {
        // Une cellule vivante survit avec 2 ou 3 voisines vivantes.
        if (voisinsVivants == 2 || voisinsVivants == 3) {
            return true;
        }
    }

    // Une cellule morte devient vivante avec exactement 3 voisines vivantes.
    if (voisinsVivants == 3) {
        return true;
    }

    return false;
}