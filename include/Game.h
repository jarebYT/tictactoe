#ifndef GAME_H
#define GAME_H

#include "Joueur.h"
#include "Grille.h"
#include <array>
#include <vector>

class Game
{
    private:
        Joueur j1;
        Joueur j2;
        Joueur* currentPlayer;
        Grille grid;
        
    public:
        Game();
        void start();
        Case play(int col, int caseNum);
        vector<array<Case*, 3>> getCombinaisons(Case square);
        bool checkWin(vector<array<Case*, 3>> combinaison_list);
};

#endif