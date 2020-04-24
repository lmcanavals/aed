#include <iostream>
#include "queuearray.h"
#include "queuelist.h"

using namespace std;

int main() {
    QueueArray* qa = new QueueArray(20);
    QueueList* ql = new QueueList();

    for (int i = 0; i < 25; ++i) {
        qa->push(i * 10);
        ql->push(i * 11);
    }

    while (!qa->is_empty()) {
        cout << qa->front() << " ";
        qa->pop();
    }
    cout << endl;

    while (!ql->is_empty()) {
        cout << ql->front() << " ";
        ql->pop();
    }
    cout << endl;

    delete qa;
    delete ql;

    return 0;
}
