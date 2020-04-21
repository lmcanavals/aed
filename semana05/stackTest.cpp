#include <iostream>
#include "stackarray.h"
#include "stacklist.h"

using namespace std;

int main() {
    StackArray* sa = new StackArray(20);
    StackList* sl = new StackList();

    for (int i = 0; i < 25; ++i) {
        sa->push(i * 10);
        sl->push(i * 11);
    }

    while (!sa->is_empty()) {
        cout << sa->top() << " ";
        sa->pop();
    }
    cout << endl;

    while (!sl->is_empty()) {
        cout << sl->top() << " ";
        sl->pop();
    }
    cout << endl;

    delete sa;
    delete sl;
    return 0;
}
