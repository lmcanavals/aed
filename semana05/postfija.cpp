#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string elem;
    stack<float> pilin;

    for (;;) {
        cout << "Expresión postfija: ";
        cin >> elem;
        if (elem == "exit") {
            break;
        }
        while (elem != ".") {
            if (elem[0] >= '0' && elem[0] <= '9'
                    || (elem[0] == '-' && elem.size() > 1)) {
                pilin.push(stof(elem));
            } else {
                float b = pilin.top(); pilin.pop();
                float a = pilin.top(); pilin.pop();
                switch (elem[0]) {
                case '+': pilin.push(a + b); break;
                case '-': pilin.push(a - b); break;
                case '*': pilin.push(a * b); break;
                case '/': pilin.push(a / b); break;
                }
            }
            cin >> elem;
        }
        cout << pilin.top() << endl; pilin.pop();
    }
    return 0;
}

