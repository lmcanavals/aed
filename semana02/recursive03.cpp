/*
n = 4
*
**
***
****
*/

#include <iostream>

using namespace std;

void stars(int n) {
    if (n == 0) {
        cout << endl;
    } else {
        cout << "*";
        stars(n - 1);
    }
}

void triangle(int n) {
    if (n > 0) {
        triangle(n - 1);
        stars(n);
    }
}

int main() {
    triangle(6);
    return 0;
}

