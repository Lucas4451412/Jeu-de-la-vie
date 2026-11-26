#pragma once

#include "Vue.h"

class VueConsole : public Vue {
public:
    void afficher(const Grille& grille, int generation) const override;
};