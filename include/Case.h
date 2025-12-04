#ifndef CASE_H
#define CASE_H

#include <string>
#include <optional>

using namespace std;

class Case {
private:
    int x;
    int y;
    optional<string> token;

public:
    Case();
    Case(int xCoord, int yCoord);
    int getX() const;
    int getY() const;
    void setToken(const string& value);
    optional<string>& getToken();
    void clearToken();

    void display();
    bool hasToken();

};

#endif