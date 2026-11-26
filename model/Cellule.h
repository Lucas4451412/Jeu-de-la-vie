#pragma once

#include "EtatCellule.h"

class Cellule {
private:
    const EtatCellule* etat;

public:
    Cellule();

    bool estVivante() const;
    TypeEtat getTypeEtat() const;
    const EtatCellule* getEtat() const;

    void definirEtat(const EtatCellule* nouvelEtat);
};