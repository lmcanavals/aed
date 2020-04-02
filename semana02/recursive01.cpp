#include <iostream>

using namespace std;

void printNSeries(int n) {
    if (n > 0) {
        printNSeries(n-1);
        cout << n << " ";
    } else {
        cout << endl;
    }
}

int main() {
    printNSeries(10);
    return 0;
}

