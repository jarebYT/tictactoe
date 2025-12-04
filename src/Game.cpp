#include "../include/Game.h"
#include <iostream>

using namespace std;

Game::Game() : j1(), j2(), grid()
{
    currentPlayer = &j1;
}

void Game::start()
{
    j1.setNom("Joueur 1");
    j2.setNom("Joueur 2");
    j1.setToken("x");
    j2.setToken("o");
    int selectedCol;
    int selectedCase;
    while (true)
    {
        grid.display();
        cout << "Joueur : " << currentPlayer->getNom() << endl;
        cout << "Choisissez une ligne entre 1 et 3" << endl;
      
        while (!(cin >> selectedCol) || selectedCol < 1 || selectedCol > 3)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Colonne invalide, choisissez une colonne entre 1 et 3" << endl;
        }

        cout << "Choisissez une case entre 1 et 3" << endl;
        while (!(cin >> selectedCase) || selectedCase < 1 || selectedCase > 3)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Case invalide, choisissez une case entre 1 et 3" << endl;
        }
      
        selectedCol -= 1;
        selectedCase -=1;
        Case square = play(selectedCol, selectedCase);
        vector<array<Case *, 3>> combinaison_list = getCombinaisons(square);
        if (checkWin(combinaison_list))
        {
            grid.display();
            break;
        }
        if (currentPlayer == &j1)
        {
            currentPlayer = &j2;
        }
        else
        {
            currentPlayer = &j1;
        }
    }
    cout << "Vainqueur :" << currentPlayer->getNom() << endl;
    cout << "Partie terminee" << endl;
    system("pause");
}

Case Game::play(int col, int caseNum)
{
    Colonne &currentCol = grid.getColonne(col);
    for (int i = currentCol.getCaseNumber() - 1; i >= 0; i--)
    {
        if (!currentCol.getCase(caseNum).hasToken())
        {
            currentCol.getCase(caseNum).setToken(currentPlayer->getToken());
            return currentCol.getCase(caseNum);
        }
    }
}

vector<array<Case *, 3>> Game::getCombinaisons(Case square)
{
    vector<array<Case *, 3>> combinaison_list;
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Case *, 3> combinaison;
        bool exist = true;
        for (int x = square.getX() + index; x <= square.getX() + index + 2; x++)
        {
            if (grid.colonneExist(x) && grid.getColonne(x).caseExist(square.getY()))
            {
                combinaison[i++] = &grid.getColonne(x).getCase(square.getY());
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Case *, 3> combinaison;
        bool exist = true;
        for (int y = square.getY() + index; y <= square.getY() + index + 2; y++)
        {
            if (grid.colonneExist(square.getX()) && grid.getColonne(square.getX()).caseExist(y))
            {
                combinaison[i++] = &grid.getColonne(square.getX()).getCase(y);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Case *, 3> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 2; xy++)
        {
            if (grid.colonneExist(square.getX() - xy) && grid.getColonne(square.getX() - xy).caseExist(square.getY() - xy))
            {
                combinaison[i++] = &grid.getColonne(square.getX() - xy).getCase(square.getY() - xy);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Case *, 3> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 2; xy++)
        {
            if (grid.colonneExist(square.getX() - xy) && grid.getColonne(square.getX() - xy).caseExist(square.getY() + xy))
            {
                combinaison[i++] = &grid.getColonne(square.getX() - xy).getCase(square.getY() + xy);
            }
            else
            {
                exist = false;
                break;
            }
        }
        if (exist)
        {
            combinaison_list.push_back(combinaison);
        }
    }
    return combinaison_list;
}

bool Game::checkWin(vector<array<Case *, 3>> combinaison_list)
{
    for (int index = 0; index < combinaison_list.size(); index++)
    {

        array<Case *, 3> combinaison = combinaison_list[index];
        if (combinaison[0]->getToken().has_value() &&
            combinaison[1]->getToken().has_value() &&
            combinaison[2]->getToken().has_value())
        {
            string token = combinaison[0]->getToken().value_ref();
            if (token == combinaison[1]->getToken().value_ref() &&
                token == combinaison[2]->getToken().value_ref())
            {
                
                return true;
            }
        }
    }
    return false;
}