#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll myHash(string key) {
    ll sum = 0;
    for (char chr : key) {
        sum += chr;
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
