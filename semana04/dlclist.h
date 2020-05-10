#ifndef __DLCLIST_H__
#define __DLCLIST_H__

#include <functional>

template <typename T, typename R=T, T NONE=0>
class DLCList {
    struct Node {
        T       elem;
        Node*   next;
        Node*   prev;

        Node(T elem, Node* p=nullptr, Node* n=nullptr)
            : elem(elem), next(n), prev(p) {}
    };

    Node*   head;
    int     length;

    std::function<R(T)> key;
public:
    /*
    DLCList() {
        key = [](T a) { return a; };
        head = nullptr;
        length = 0;
    }
    DLCList(std::function<R(T)> key) {
        this->key = key;
        head = nullptr;
        length = 0;
    }
    // TOdo esto es equivalente al constructorcito brutal de abajo
    */

    DLCList(std::function<R(T)> key=[](T a) { return a; })
        : head(nullptr), length(0), key(key) {}
    ~DLCList() {
        clear();
    }

    int size() {
        return length;
    }

    bool empty() {
        return length == 0;
    }

    void addFirst(T elem) {
        if (length == 0) {
            head = new Node(elem);
            head->next = head;
            head->prev = head;
        } else {
            auto newest = new Node(elem, head->prev, head);
            head->prev = newest;
            newest->prev->next = newest;
            head = newest;
        }
        ++length;
    }

    void addLast(T elem) {
        if (length == 0) {
            addFirst(elem);
        } else {
            auto newest = new Node(elem, head->prev, head);
            head->prev = newest;
            newest->prev->next = newest;
            ++length;
        }
    }

    void addPos(T elem, int pos) {
        if (pos == 0) {
            addFirst(elem);
        } else {
            auto aux = head;
            if (pos > 0 && pos <= length) {
                for (int i = 1; i < pos; ++i) {
                    aux = aux->next;
                }
                auto newest = new Node(elem, aux, aux->next);
                aux->next->prev = newest;
                aux->next = newest;
            } else if (pos < 0 && -pos <= length) {
                for (int i = -1; i > pos; --i) {
                    aux = aux->prev;
                }
                auto newest = new Node(elem, aux->prev, aux);
                aux->prev->next = newest;
                aux->prev = newest;
            } else {
                return;
            }
            ++length;
        }
    }

    void removeFirst() {
        if (length == 0) {
            return;
        }
        if (length == 1) {
            delete head;
            head = nullptr;
        } else {
            auto aux = head;
            head = head->next;
            head->prev = aux->prev;
            aux->prev->next = head;
            delete aux;
        }
        --length;
    }

    void removeLast() {
        if (length == 0) {
            return;
        }
        if (length == 1) {
            delete head;
            head = nullptr;
        } else {
            auto aux = head->prev;
            aux->prev->next = head;
            head->prev = aux->prev;
            delete aux;
        }
        --length;
    }

    void removePos(int pos) {
        if (length == 0) {
            return;
        }
        if (pos == 0) {
            removeFirst();
        } else {
            auto aux = head;
            if (pos > 0 && pos < length) {
                for (int i = 1; i < pos; ++i) {
                    aux = aux->next;
                }
                auto aux2 = aux->next;
                aux->next = aux2->next;
                aux2->next->prev = aux;
                delete aux2;
            } else if (pos < 0 && -pos < length) {
                for (int i = -1; i > pos; --i) {
                    aux = aux->prev;
                }
                auto aux2 = aux->prev;
                aux->prev = aux2->prev;
                aux2->prev->next = aux;
                delete aux2;
            } else {
                return;
            }
            --length;
        }
    }

    void modifyFirst(T elem) {
        if (length > 0) {
            head->elem = elem;
        }
    }

    void modifyLast(T elem) {
        if (length > 0) {
            head->prev->elem = elem;
        }
    }

    void modifyPos(T elem, int pos) {
        if (length > 0) {
            auto aux = head;
            if (pos >= 0 && pos < length) {
                for (int i = 0; i < pos; ++i) {
                    aux = aux->next;
                }
            } else if (pos < 0 && -pos < length) {
                for (int i = 0; i > pos; --i) {
                    aux = aux->prev;
                }
            }
            aux->elem = elem;
        }
    }

    T getFirst() {
        if (length > 0) {
            return head->elem;
        }
        return NONE;
    }

    T GetLast() {
        if (length > 0) {
            return head->prev->elem;
        }
        return NONE;
    }

    T getPos(int pos) {
        if (length > 0) {
            auto aux = head;
            if (pos >= 0 && pos < length) {
                for (int i = 0; i < pos; ++i) {
                    aux = aux->next;
                }
            } else if (pos < 0 && -pos < length) {
                for (int i = 0; i > pos; --i) {
                    aux = aux->prev;
                }
            }
            return aux->elem;
        }
        return NONE;
    }

    void clear() {
        for (int i = 0; i < length; ++i) {
            auto aux = head;
            head = aux->next;
            delete aux;
        }
        length = 0;
    }

    T find(R value) {
        auto aux = head;
        for (int i = 0; i < length; ++i) {
            if (key(aux->elem) == value) {
                return aux->elem;
            }
            aux = aux->next;
        }
        return NONE;
    }

    class iterator {
        Node* aux;
        int pos;
    public:
        iterator(int pos = 0, Node* aux = nullptr) : pos(pos), aux(aux) {}
        bool operator!=(iterator o) {
            return this->pos != o.pos;
        }
        void operator++() {
            ++pos;
            aux = aux->next;
        }
        T operator*() {
            return aux->elem;
        }
    };

    iterator begin() {
        return iterator(0, head);
    }

    iterator end() {
        return iterator(length);
    }
};

#endif

