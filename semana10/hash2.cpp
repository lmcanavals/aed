#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;

ll myHash(string key) {
    ll sum = 0;
    int exp = key.size() - 1;
    for (char chr : key) {
        sum += (chr-96)*pow(27, exp--);
    }
    return sum;
}

int main() {
    string key;
    for (;;) {
        cout << "Clave: ";
        cin >> key;
        if (key == ".") break;
        cout << key << " -> " << myHash(key) << endl;
    }
    return 0;
}
