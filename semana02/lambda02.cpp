#include <iostream>
#include <functional>

using namespace std;

int main() {
    auto                          f2 = [](float a, float b) { return a / b; };
    function<float(float, float)> f1 = [](float a, float b) { return a * b; };

    auto  x2 = 10.56f;
    float x1 = 10.56f;

    cout << f1(4, 8) << endl
         << f1(6, 1.5) << endl
         << f2(4, 8) << endl
         << f2(6, 1.5) << endl;

    cout << endl;

    cout << typeid(f1).name() << endl
         << typeid(f2).name() << endl
         << typeid(x1).name() << endl
         << typeid(x2).name() << endl;

    return 0;
}
