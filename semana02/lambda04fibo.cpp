#include <iostream>
#include <functional>

using namespace std;

int main() {
    function<int(int)> fibo = [&](int n) {
        if (n < 2) {
            return n;
        } else {
            return fibo(n-1) + fibo(n-2);
        }
    };

    cout << fibo(10) << endl;

    function<void(int,int,int)> fibo2 = [&](int n, int t1, int t2) {
        if (n > 0) {
            cout << t1 << " ";
            fibo2(n - 1, t2, t1 + t2);
        }
    };
    fibo2(10, 1, 1);
    cout << endl;

    int t1 = 1;
    int t2 = 1;
    function<int()> fibo3 = [&]() {
        auto t = t1;
        t1 = t2;
        t2 = t + t2;
        return t;
    };

    for (int i = 0; i < 10; i++) {
        cout << fibo3() << " ";
    }
    cout << endl;

    return 0;
}
