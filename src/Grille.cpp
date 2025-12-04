#include "Grille.h"
#include <iostream>

using namespace std;

Grille::Grille() {
    for(int x = 0; x<3; x++) {
        colonne_list[x] = Colonne(x);
    }
}

void Grille::display() {
    system("cls");
    for(int col = 0; col < colonne_list.size() ; col++) {
        colonne_list[col].display();
    }

}

Colonne& Grille::getColonne(int xCoord) {
    return colonne_list[xCoord];
};

void Grid::reset(){
    for(int col = 0; col < colonne_list.size() ; col++) {
        for(int x = 0; x < 3; x++){
            colonne_list[col].getCase(x).getToken().reset();
        }
    }
}

bool Grille::colonneExist(int xCoord){
    return xCoord >= 0 && xCoord < colonne_list.size();
}