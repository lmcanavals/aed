#include <iostream>

using namespace std;

long long fclassic(int n) {
    long long f = 1;
    for (int i = 2; i <= n; ++i) {
        f = f * i;
    }
    return f;
}

long long factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    cout << fclassic(5) << endl;
    cout << factorial(5) << endl;
    return 0;
}
