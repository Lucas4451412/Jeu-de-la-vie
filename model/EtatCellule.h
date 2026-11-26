#pragma once

// Énumération utile pour identifier rapidement un état (ex: dans la Vue ou les fichiers)
enum class TypeEtat {
    Morte,
    Vivante
    // Tu pourras simplement ajouter Mur, Zombie, etc. ici
};

class EtatCellule {
public:
    virtual ~EtatCellule() = default;

    // Indique si l'état compte comme un voisin vivant pour les règles classiques
    virtual bool estVivante() const = 0;

    // Permet à la Vue ou au GestionnaireFichier de connaître le type exact sans dynamic_cast
    virtual TypeEtat getType() const = 0;
};

class EtatVivante : public EtatCellule {
private:
    EtatVivante() = default; // Constructeur privé pour forcer l'utilisation de instance()

public:
    static const EtatVivante* instance();

    bool estVivante() const override;
    TypeEtat getType() const override;
};

class EtatMorte : public EtatCellule {
private:
    EtatMorte() = default;

public:
    static const EtatMorte* instance();

    bool estVivante() const override;
    TypeEtat getType() const override;
};