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
        Case play(int col);
        vector<array<Case*, 4>> getCombinaisons(Case square);
        bool checkWin(vector<array<Case*, 4>> combinaison_list);
        void drawCombinaison();
};

#endif