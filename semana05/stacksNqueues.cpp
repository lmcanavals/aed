#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// invertir una pila usando solo pilas
void invertStack(stack<int>& st) {
    stack<int> aux1;
    stack<int> aux2;
    while (!st.empty()) {
        aux1.push(st.top());
        st.pop();
    }
    while (!aux1.empty()) {
        aux2.push(aux1.top());
        aux1.pop();
    }
    while (!aux2.empty()) {
        st.push(aux2.top());
        aux2.pop();
    }
}

// invertir una cola usando solo colas
void invertQueue(queue<int>& q) {
    queue<int> q1, q2;
    queue<int>* aux1 = &q1;
    queue<int>* aux2 = &q2;

    while (!q.empty()) {
        aux1->push(q.front());
        q.pop();
    }
    while (!(aux1->empty() && aux2->empty())) {
        while (aux1->size() > 1) {
            aux2->push(aux1->front());
            aux1->pop();
        }
        q.push(aux1->front());
        aux1->pop();
        queue<int>* temp = aux1;
        aux1 = aux2;
        aux2 = temp;
    }
}

int main() {
    stack<int> st;
    queue<int> q;

    for (int i = 0; i < 10; ++i) {
        st.push(i * 10);
        q.push(i * 11);
    }
    invertStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    invertQueue(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
