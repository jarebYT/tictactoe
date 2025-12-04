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
    while (true)
    {
        grid.display();
        cout << "Joueur : " << currentPlayer->getNom() << endl;
        cout << "Choisissez une colonne entre 1 et 3" << endl;
        cin >> selectedCol;
        selectedCol - 1;
        Case square = play(selectedCol);
        vector<array<Case *, 4>> combinaison_list = getCombinaisons(square);
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

Case Game::play(int col)
{
    Colonne &currentCol = grid.getColonne(col);
    for (int i = currentCol.getCaseNumber() - 1; i >= 0; i--)
    {
        if (!currentCol.getCase(i).hasToken())
        {
            currentCol.getCase(i).setToken(currentPlayer->getToken());
            return currentCol.getCase(i);
        }
    }
}

vector<array<Case *, 4>> Game::getCombinaisons(Case square)
{
    vector<array<Case *, 4>> combinaison_list;
    for (int index = -3; index <= 0; index++)
    {
        int i = 0;
        array<Case *, 4> combinaison;
        bool exist = true;
        for (int x = square.getX() + index; x <= square.getX() + index + 3; x++)
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
        array<Case *, 4> combinaison;
        bool exist = true;
        for (int y = square.getY() + index; y <= square.getY() + index + 3; y++)
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
        array<Case *, 4> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 3; xy++)
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
        array<Case *, 4> combinaison;
        bool exist = true;
        for (int xy = index; xy <= index + 3; xy++)
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

void Game::drawCombinaison()
{
    auto combinaison_list = getCombinaisons(grid.getColonne(4).getCase(4));
    for (int c = 0; c <= combinaison_list.size() - 1; c++)
    {
        for (int s = 0; s <= combinaison_list[c].size() - 1; s++)
        {
            combinaison_list[c][s]->setToken("x");
        }
        grid.display();
        system("pause");
        grid.reset();
    }
}

bool Game::checkWin(vector<array<Case *, 4>> combinaison_list)
{
    for (int index = 0; index < combinaison_list.size(); index++)
    {

        array<Case *, 4> combinaison = combinaison_list[index];
        if (combinaison[0]->getToken().has_value() &&
            combinaison[1]->getToken().has_value() &&
            combinaison[2]->getToken().has_value() &&
            combinaison[3]->getToken().has_value())
        {
            string token = combinaison[0]->getToken().value();
            if (token == combinaison[1]->getToken().value() &&
                token == combinaison[2]->getToken().value() &&
                token == combinaison[3]->getToken().value())
            {
                
                return true;
            }
        }
    }
    return false;
}