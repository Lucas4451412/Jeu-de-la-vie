#pragma once

class Grille;

// Interface commune à toutes les vues (Console, SFML, etc.)
class Vue {
public:
    virtual ~Vue() = default;

    virtual void afficher(const Grille& grille, int generation) const = 0;
};