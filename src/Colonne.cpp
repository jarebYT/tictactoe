//
// Created by flopr on 04/12/2025.
//

#include "Colonne.h"
#include <iostream>

using namespace std;

Colonne::Colonne() : x(0) {}

Colonne::Colonne(int xCoord) : x(xCoord) {
    for(int y = 0; y<3; y++) {
        case_list[y] = Case(xCoord,y);
    }
}

int Colonne::getX() const { return x; }

void Colonne::display() {
    cout << "|";
    for(int i = case_list.size() -1; i>= 0; --i) {
        case_list[i].display();
    }
    cout << "|" << endl;
}

Case& Colonne::getCase(int yCoord) {
    return case_list[yCoord];
};

int Colonne::getCaseNumber(){
    return case_list.size();
}

bool Colonne::caseExist(int yCoord){
    return yCoord >= 0 && yCoord < case_list.size();
}