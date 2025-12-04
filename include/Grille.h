#ifndef GRILLE_H
#define GRILLE_H

#include <array>
#include "Colonne.h"

class Grille {
private:
    array<Colonne,3> colonne_list;
public:
    Grille();
    void display();
    Colonne& getColonne(int xCoord);
    void reset();
    bool colonneExist(int xCoord);
};

#endif