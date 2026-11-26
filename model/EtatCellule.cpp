#include "EtatCellule.h"

const EtatVivante* EtatVivante::instance() {
    static const EtatVivante instanceUnique;
    return &instanceUnique;
}

bool EtatVivante::estVivante() const {
    return true;
}

TypeEtat EtatVivante::getType() const {
    return TypeEtat::Vivante;
}

const EtatMorte* EtatMorte::instance() {
    static const EtatMorte instanceUnique;
    return &instanceUnique;
}

bool EtatMorte::estVivante() const {
    return false;
}

TypeEtat EtatMorte::getType() const {
    return TypeEtat::Morte;
}