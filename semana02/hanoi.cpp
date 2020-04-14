// hanoi
//

#include <iostream>

using namespace std;

void hanoi(int n, char a, char b, char c) {
    if (n > 0) {
        hanoi(n - 1, a, c, b);
        cout << "Mover disco " << n << " de " << a << " a " << b << endl;
        hanoi(n - 1, c, b, a);
    }
}

int main() {
    hanoi(4, 'A', 'C', 'B');
    return 0;
}
