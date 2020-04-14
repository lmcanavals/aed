#include <iostream>
#include "listfloat.h"

using namespace std;

int main() {
    ListFloat* lst = new ListFloat();

    for (int i = 0; i < 10; ++i) {
        lst->addFirst(4.5*i);
        lst->addFinal(3.7*i);
    }
    lst->addPos(1000.0, 9);
    lst->deletePos(3);

    cout << lst->getFirst() << endl;
    lst->deleteFirst();

    for (auto f : *lst) {
        cout << f << " ";
    }
    cout << endl;

    delete lst;
    return 0;
}

