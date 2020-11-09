%%writefile 2.cpp
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class pht {

    vector<bool> elements;
    int c1;
    int c2;
    int m;
    int n;

public:
    pht(int cap, int c1, int c2, int n, int m) : elements(cap, false), c1(c1), n(n), c2(c2), m(m) {}

    int add(int k, bool showCandidates=false) {
        for (int i = 0; i < elements.size(); ++i) {
            auto idx = h(k, i);
            if (!elements[idx]) {
                elements[idx] = true;
                return idx;
            } else if (showCandidates) {
                printf("(%d) ", idx);
            }
        }
    }

private:
    int hprima(int k) {
        float sum = 0.f;
        for (int j = 0; j <= k; ++j) {
            sum += (c1/c2)*j;
        }
        return int(floor(sum)) % n;
    }

    int h(int k, int i) {
        return (hprima(k) + c1*i + c2*i*i) % m;
    }
};

int main() {vector<int> keys = { 208, 408, 624, 816, 1040, 1248, 1428, 1664, 1836, 2080, 2244, 2496, 2652, 2912, 3060, 3328, 3468, 3744 };
    pht* ht = new pht(1000, 6, 12, 109, 113);

    for (auto k : keys) {
        printf("%d\n", ht->add(k));
    }

    delete ht;

    return 0;
}
