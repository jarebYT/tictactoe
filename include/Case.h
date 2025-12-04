#ifndef CASE_H
#define CASE_H

#include <string>

using namespace std;

class Case {
private:
    int x;
    int y;
    string token;

public:
    Case();
    Case(int xCoord, int yCoord);
    int getX() const;
    int getY() const;
    void setToken(const string& value);
    string& getToken();
    void clearToken();

    void display();
    bool hasToken();

};

#endif