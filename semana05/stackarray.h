#ifndef __STACKARRAY_H__
#define __STACKARRAY_H__

class StackArray {
    float* elems;
    int posTop;
    int capacity;
public:
    StackArray(int capacity=10)
        : elems(new float[capacity]), posTop(0), capacity(capacity) {}
    ~StackArray() {
        delete[] elems;
    }

    bool push(float elem) {
        if (posTop < capacity) {
            elems[posTop++] = elem;
            return true;
        }
        return false;   // no se logró insertar por pila llena
    }

    bool pop() {
        if (posTop > 0) {
            --posTop;
            return true;
        }
        return false;
    }

    int size() {
        return posTop;
    }
    float top() {
        if (posTop > 0) {
            return elems[posTop - 1];
        }
        return -0.0001; // no hay nada;
    }

    bool is_empty() {
        return posTop == 0;
    }

    bool is_full() {
        return posTop == capacity;
    }
};

#endif
