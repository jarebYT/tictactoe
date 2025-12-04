#ifndef COLONNE_H
#define COLONNE_H

#include <array>
#include "Case.h"

class Colonne {
private:
    int x;
    array<Case,3> case_list;
public:
    Colonne();
    Colonne(int xCoord);
    int getX() const;
    void display();
    Case& getCase(int yCoord);
    int getCaseNumber();
    bool caseExist(int yCoord);
};

#endif