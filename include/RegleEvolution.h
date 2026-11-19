

// Définit la méthode commune à toutes les règles d'évolution.
class RegleEvolution {
public:
    // Renvoie true si la cellule sera vivante à la prochaine génération.
    virtual bool determinerEtatSuivant(bool vivante, int voisinsVivants) const = 0;

    virtual ~RegleEvolution() = default;
};

// Représente la règle classique du Jeu de la vie.
class RegleConway : public RegleEvolution {
public:
    bool determinerEtatSuivant(bool vivante, int voisinsVivants) const override;
};

