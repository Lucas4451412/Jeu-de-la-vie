#include "Cellule.h"

Cellule::Cellule() : etat(EtatMorte::instance()) {}

bool Cellule::estVivante() const {
    return etat->estVivante();
}

TypeEtat Cellule::getTypeEtat() const {
    return etat->getType();
}

const EtatCellule* Cellule::getEtat() const {
    return etat;
}

void Cellule::definirEtat(const EtatCellule* nouvelEtat) {
    if (nouvelEtat != nullptr) {
        etat = nouvelEtat;
    }
}