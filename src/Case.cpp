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

Optional<string>& Case::getToken() {
    return token;
}

void Case::setToken(const string& value) {
    token = value;
}

void Case::clearToken() {
    token.reset();
}

void Case::display() {
    cout << "[";
    if (token.has_value() && token.value_ref() != "") {
        cout << token.value_ref();
    } else {
        cout << " ";
    }
    cout << "]";
}

bool Case::hasToken() {
    return token.has_value() && token.value_ref() != "";
}