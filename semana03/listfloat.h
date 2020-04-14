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
    void addPos(float elem, int pos) {
        if (pos < 0 || pos > len) {
            return;
        } else if (pos == 0) {
            addFirst(elem);
        } else {
            auto aux = head;
            for (int c = 1; c < pos; ++c) {
                aux = aux->next;
            }
            aux->next = new Node(elem, aux->next);
            ++len;
        }
    }
    void addFinal(float elem) {
        addPos(elem, len);
    }
    void deleteFirst() {
        if (len > 0) {
            auto aux = head;
            head = head->next;
            delete aux;
            --len;
        }
    }
    void deletePos(int pos) {
        if (pos < 0 || pos >= len) {
            return;
        } else if (pos == 0) {
            deleteFirst();
        }  else {
            auto aux = head;
            for (int c = 1; c < pos; ++c) {
                aux = aux->next;
            }
            auto aux2 = aux->next;
            aux->next = aux2->next;
            delete aux2;
            --len;
        }
    }
    void deleteFinal() {
        deletePos(len - 1);
    }
    float getFirst() {
        if (len > 0) {
            return head->elem;
        }
        return -0.000001;
    }
    float getPos(int pos) {
        if (pos < 0 || pos >= len) {
            return -0.000001;
        } else if (pos == 0) {
            return getFirst();
        } else {
            auto aux = head;
            for (int c = 0; c < pos; ++c) {
                aux = aux->next;
            }
            return aux->elem;
        }
    }
    float getLast() {
        return getPos(len - 1);
    }
    int findPos(float elem) {
        auto aux = head;
        for (int i = 0; i < len; ++i) {
            if (aux->elem == elem) {
                return i;
            }
        }
        return -1;
    }
};

#endif

