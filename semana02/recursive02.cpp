#include <iostream>

using namespace std;

void printNSeries(int n) {
    if (n > 0) {
        cout << n << " ";
        printNSeries(n-1);
    }
}

int main() {
    printNSeries(10);
    return 0;
}

