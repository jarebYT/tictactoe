#include <iostream>
#include "../include/Myclass.h" // On inclut le .h pour utiliser la classe

using namespace std;

int main() {
    // Création d’un objet avec le constructeur par défaut
    MyClass a;
    a.setValue(12);
    a.print();   // Affiche : Value = 12

    // Création d’un objet avec le constructeur paramétré
    MyClass b(42);
    cout << "b contient : " << b.getValue() << endl;

    return 0;
}
