#include <iostream>
#include <functional>
#include <string>
#include <string.h>

using namespace std;

// formato de string yyyy-mm-dd HH:MM

void printFecha(string fecha, function<string(string)> procFecha) {
    cout << procFecha(fecha) << endl;
}

int main() {
    auto pfYear = [](string fecha) {
        char* f = new char[fecha.size() + 1];
        strcpy(f, fecha.c_str());
        f[4] = 0;
        string resp(f);
        delete f;
        return resp;
    };

    auto pfMonth = [](string fecha) {
        return fecha.substr(5, 2);
    };

    printFecha("1981-05-12", pfYear);
    printFecha("1981-05-12", pfMonth);

    return 0;
}
