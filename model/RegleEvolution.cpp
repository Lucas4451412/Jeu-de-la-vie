#include "RegleEvolution.h"
#include "EtatCellule.h"

const EtatCellule* RegleConway::determinerEtatSuivant(const EtatCellule* etatActuel, int voisinsVivants) const {
    if (etatActuel->estVivante()) {
        if (voisinsVivants == 2 || voisinsVivants == 3) {
            return EtatVivante::instance();
        }
        return EtatMorte::instance();
    }

    if (voisinsVivants == 3) {
        return EtatVivante::instance();
    }

    return EtatMorte::instance();
}