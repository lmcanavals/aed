#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T mayor(T* arr, int n) {
    if (n <= 0) return 0;
    T m = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    return m;
}

template <typename T>
int mayorInVec(vector<T> arr) {
    int n = arr.size();
    if (n <= 0) return 0;
    T m = arr[0];
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > m) {
            m = arr[i];
            idx = i;
        }
    }
    return idx;
}

template <typename T>
T moda(vector<T> arr) {
    int max = arr[mayorInVec(arr)];
    vector<T> cont(max+1, 0);
    for (int i = 0; i < arr.size(); ++i) {
        cont[arr[i]]++;
    }
    return mayorInVec(cont);
}

int main() {
    vector<int> v={ 5, 1, 7, 8, 1, 2, 5, 3, 4, 6,
                    7, 4, 4, 5, 5, 6, 7, 8, 9, 7,
                    4, 5, 6, 7, 6, 4, 5, 6, 4, 4,
                    4, 4};
    cout << moda(v) << endl;
    return 0;
}
