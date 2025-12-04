#ifndef CASE_H
#define CASE_H

#include <string>
#include <Optional.h>

using namespace std;

class Case {
private:
    int x;
    int y;
    Optional<string> token;

public:
    Case();
    Case(int xCoord, int yCoord);
    int getX() const;
    int getY() const;
    void setToken(const string& value);
    Optional<string>& getToken();
    void clearToken();

    void display();
    bool hasToken();

};

#endif