#pragma once

class EtatCellule; // Déclaration anticipée

class RegleEvolution {
public:
    virtual ~RegleEvolution() = default;

    // Renvoie le pointeur vers le prochain état de la cellule
    virtual const EtatCellule* determinerEtatSuivant(const EtatCellule* etatActuel, int voisinsVivants) const = 0;
};

class RegleConway : public RegleEvolution {
public:
    const EtatCellule* determinerEtatSuivant(const EtatCellule* etatActuel, int voisinsVivants) const override;
};