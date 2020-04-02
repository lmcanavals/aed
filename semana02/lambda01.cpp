#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Estudiante {
public: string nombre;
    float promedio;
    Estudiante(string nombre, float promedio) : nombre(nombre), promedio(promedio) {}
    string ToString() {
        stringstream ss;

        ss << nombre << " - " << promedio;
        return ss.str();
    }
};

template <typename T, typename R=T>
void sort(vector<T>& a, function<R(T)> key) {
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = 0; j < a.size() - 1 - i; ++j) {
            if (key(a[j]) > key(a[j + 1])) {
                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    vector<Estudiante> estudiantes = { Estudiante("Juan", 20),
                                       Estudiante("Rosa", 16), Estudiante("Alonso", 18)};

    auto keyNombre = [](Estudiante e) { return e.nombre; };
    auto keyProm = [](Estudiante e) {return e.promedio; };

    sort<Estudiante, string>(estudiantes, keyNombre);
    for (auto e : estudiantes) {
        cout << e.ToString() << endl;
    }
    cout << endl;

    sort<Estudiante, float>(estudiantes, keyProm);
    for (auto e : estudiantes) {
        cout << e.ToString() << endl;
    }
    return 0;
}
