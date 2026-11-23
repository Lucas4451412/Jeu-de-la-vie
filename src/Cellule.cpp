#include "Cellule.h"

Cellule::Cellule(bool etatInitial) : etat(etatInitial) {}

bool Cellule::estVivante() const {
    return etat;
}

void Cellule::definirEtat(bool nouvelEtat) {
    etat = nouvelEtat;
}