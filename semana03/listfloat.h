#ifndef __LISTFLOAT_H__
#define __LISTFLOAT_H__

class ListFloat {
    struct Node {
        float elem;
        Node* next;

        Node(float elem, Node* next = nullptr) : elem(elem), next(next) {}
    };

    Node* head;
    int   len;

public:
    ListFloat() : head(nullptr), len(0) {}
    ~ListFloat() {
        while (head != nullptr) {
            auto aux = head;
            head = head->next;
            delete aux;
        }
    }

    int size() {
        return len;
    }
    bool is_empty() {
        return len == 0;
    }
    void addFirst(float elem) {
        head = new Node(elem, head);
        ++len;
    }
};

#endif

