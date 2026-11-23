#include "Cellule.h"

Cellule::Cellule() {
    static EtatMorte etatMort;
    etat = &etatMort;
}


bool Cellule::estVivante() const {
    return etat->estVivante();
}

void Cellule::definirEtat(EtatCellule* nouvelEtat) {
    etat = nouvelEtat;
}

bool EtatVivante::estVivante() const {
        return true;
}

bool EtatMorte::estVivante() const {
        return false;
}