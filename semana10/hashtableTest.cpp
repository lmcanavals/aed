#include <iostream>

#define DEBUG

#include "hashtable.h"

using namespace std;

int main() {
    int keys[10] = { 6, 34, 67, 92, 96, 8, 5, 3, 2, 20 };
    HashTable* ht = new HashTable();

    for (int i = 0; i < 10; ++i) {
        ht->add(keys[i]);
    }

    delete ht;
    return 0;
}
