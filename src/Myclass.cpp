#include "../include/Myclass.h"
#include <iostream>


MyClass::MyClass() : value(0) {}


MyClass::MyClass(int value) : value(value) {}


void MyClass::setValue(int v) {
value = v;
}


int MyClass::getValue() const {
return value;
}


void MyClass::print() const {
std::cout << "Value = " << value << std::endl;
}