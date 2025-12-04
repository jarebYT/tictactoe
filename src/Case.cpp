//
// Created by flopr on 04/12/2025.
//

#include "../include/Case.h"
#include <iostream>

using namespace std;

Case::Case() : x(0), y(0), token("") {}

Case::Case(int xCoord, int yCoord) : x(xCoord), y(yCoord), token("") {}

int Case::getX() const { return x; }
int Case::getY() const { return y; }

optional<string>& Case::getToken() {
    return token;
}

void Case::setToken(const string& value) {
    token = value;
}

void Case::clearToken() {
    token = "";
}

void Case::display() {
    cout << "[";
    if (token.has_value()) {
        cout << token.value();
    } else {
        cout << " ";
    }
    cout << "]";
}

bool Case::hasToken() {
    return !token.has_value();
}