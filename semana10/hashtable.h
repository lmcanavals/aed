#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#ifdef DEBUG

#include <iostream>
using namespace std;

#endif

// TODO Solo implementamos el manejo de claves por el momento.
class HashTable {
    int** keys;
    int N;

    int hprima(int k) { return k % 19; }
    int h(int k, int i) { return (hprima(k) + i) % 29; } // solo por el ejercicio de la PPT

public:
    HashTable(int N=100) : N(N), keys(new int*[N]) {} // TODO calcular el N primo
    ~HashTable() {
        for (int i = 0; i < N; ++i) {
            if (keys[i] != nullptr) {
                delete keys[i];
            }
        }
        delete[] keys;
    }

    bool add(int k) {
        bool ok = false;
        for (int i = 0; i < N; i++) {
            int idx = h(k, i);

#ifdef DEBUG
            cout << idx << " "; 
#endif

            if (keys[idx] == nullptr) {
                keys[idx] = new int;
                *(keys[idx]) = k;
                ok = true;
                break;
            }
        }

#ifdef DEBUG
        cout << endl;
#endif

        return ok;
    }
};

#endif
