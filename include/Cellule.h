#pragma once

class Cellule {
private:
    bool etat;

public:
    explicit Cellule(bool etatInitial = false);

    bool estVivante() const;
    void definirEtat(bool nouvelEtat);
};