// MyClass.h
#ifndef MYCLASS_H
#define MYCLASS_H


class MyClass {
public:
MyClass(); // Constructeur
MyClass(int value); // Constructeur avec paramètre


void setValue(int v); // Déclare une fonction
int getValue() const; // Déclare une fonction const
void print() const; // Exemple de méthode


private:
int value; // Attribut privé
};


#endif