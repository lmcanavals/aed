/*
 * n = 123456
 *
 * respuesta = 654321
 *
 *
 */

#include <iostream>

using namespace std;

typedef long long ll;

void inv(ll n) {
    if (n > 0) {
        cout << n % 10;
        inv(n / 10);
    }
}

int main() {
    inv(12345);
    return 0;
}
