#include <iostream>
#include <functional>

using namespace std;

typedef function<float(float, float)> func;


float calc(func f) {
    return f(6, 4);
}

int main() {
    auto f1 = [](float a, float b) { return a + b; };
    func f2 = [](float a, float x) { return a - x; };

    cout << calc(f1) << endl
         << calc(f2) << endl
         << calc([](float x, float y) { return x * y; }) << endl;

    return 0;
}

