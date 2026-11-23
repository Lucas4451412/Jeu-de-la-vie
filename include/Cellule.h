// Classe abstraite représentant un état possible d'une cellule.
class EtatCellule {
public:
    // Impose aux classes dérivées d'indiquer si l'état est vivant.
    virtual bool estVivante() const = 0;

    // Permet de détruire correctement un état via un pointeur EtatCellule.
    virtual ~EtatCellule() {}
};

// Représente une cellule de la grille et permet de gérer son état.
class Cellule {
private:
    // Pointeur vers l'objet représentant l'état actuel de la cellule.
    EtatCellule* etat;

public:
    Cellule();
    // Renvoie true si la cellule est vivante, sinon false.
    bool estVivante() const;

    // Change l'état de la cellule en lui associant l'objet indiqué.
    void definirEtat(EtatCellule* nouvelEtat);
};



// Représente l'état vivant d'une cellule.
class EtatVivante : public EtatCellule {
public:
    // Renvoie toujours true puisque cet objet représente l'état vivant.
    bool estVivante() const override {
        return true;
    }
};


class EtatMorte : public EtatCellule{
public:
    bool estVivante() const override{
        return false;
    }

    

};