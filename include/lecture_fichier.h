
#include <string>
#include "Grille.h"

Grille lireGrille(const std::string& nomFichier);
void afficherGrille(const Grille& grille);

void ecrireGrille(const std::string& nomFichier, const Grille& grille);