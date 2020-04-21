#ifndef __STACKLIST_H__
#define __STACKLIST_H__

class StackList {
    struct Node {
        float elem;
        Node* next;

        Node(float elem, Node* next=nullptr) : elem(elem), next(next) {}
    };

    Node* ptrTop;
    int length;

public:
    StackList() : ptrTop(nullptr), length(0) {}
    ~StackList() {
        while (ptrTop != nullptr) {
            auto aux = ptrTop;
            ptrTop = aux->next;
            delete aux;
        }
    }

    int size() {
        return length;
    }
    bool is_empty() {
        return length == 0;
    }
    void push(float elem) {
        ptrTop = new Node(elem, ptrTop);
        ++length;
    }
    bool pop() {
        if (length > 0) {
            auto aux = ptrTop;
            ptrTop = aux->next;
            delete aux;
            --length;
            return true;
        }
        return false;
    }
    float top() {
        if (length > 0) {
            return ptrTop->elem;
        }
        return 0.00001; // No se enecontro nada para retornar :)
    }
};

#endif
