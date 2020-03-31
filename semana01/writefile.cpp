#include <iostream>
#include  <fstream>
#include <string.h>
#include <string>

using namespace std;

struct Estudiante {
    char nombre[64];
    int codigo;
    float promedio;
};

void guarda(ofstream& arch, Estudiante* e) {
    arch.write((char*)e, sizeof(Estudiante));
}

int main() {
    Estudiante est;
    ofstream arch("estudiantes.out");

    string name;
    while (true) {
        cout << "Nombre: "; getline(cin, name);
        if (name == "") break;
        strcpy(est.nombre, name.c_str());
        cout << "Código: "; cin >> est.codigo;
        cout << "Promedio: "; cin >> est.promedio;
        cin.get();

        guarda(arch, &est);
    }

    arch.close();
    return 0;
}
