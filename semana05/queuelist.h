#ifndef __QUEUELIST_H__
#define __QUEUELIST_H__

class QueueList {
    struct Node {
        float elem;
        Node* next;

        Node(float e, Node* n=nullptr) : elem(e), next(n) {}
    };

    Node* ptrFront;
    Node* ptrBack;
    int   length;
public:
    QueueList() : ptrFront(nullptr), ptrBack(nullptr), length(0) {}
    ~QueueList() {
        while (ptrFront != nullptr) {
            auto aux = ptrFront;
            ptrFront = aux->next;
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
        if (++length == 1) {
            ptrFront = new Node(elem);
            ptrBack = ptrFront;
        } else {
            ptrBack->next = new Node(elem);
            ptrBack = ptrBack->next;
        }
    }
    bool pop() {
        if (length > 0) {
            auto aux = ptrFront;
            ptrFront = aux->next;
            delete aux;
            --length;
            return true;
        }
        return false;
    }
    float front() {
        if (length > 0) {
            return ptrFront->elem;
        }
        return -0.0001;
    }
};

#endif
