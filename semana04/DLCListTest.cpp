#include <iostream>
#include <string>
#include "dlclist.h"

using namespace std;

class Alumno {
    string nombre;
    string apellido;
public:
    Alumno(string n, string a) : nombre(n), apellido(a) {}
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    string str() {
        return nombre + " " + apellido;
    }
}; 

int main() {
    DLCList<int>* l1 = new DLCList<int>();

    auto kape = [](Alumno* a) { return a->getApellido(); };

    DLCList<Alumno*, string, nullptr>* l2 = new DLCList<Alumno*, string, nullptr>(kape);

    for (int i = 0; i < 10; ++i) {
        l1->addLast(i * 7);
    }

    for (auto f : *l1) {
        cout << f << " ";
    }
    cout << endl;

    cout << l1->find(14) << endl;

    l2->addFirst(new Alumno("Rosa", "Gomez"));
    l2->addFirst(new Alumno("Rosalia", "Jimenez"));
    l2->addFirst(new Alumno("Felipe", "Perez"));
    l2->addFirst(new Alumno("Manuel", "Lopez"));
    l2->addFirst(new Alumno("Maria", "Ramirez"));

    for (auto a : *l2) {
        cout << a->str() << endl;
    }
    cout << endl;

    cout << l2->find("Smith")  << " - \n";

    return 0;
};

