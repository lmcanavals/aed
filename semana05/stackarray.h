#ifndef __STACKARRAY_H__
#define __STACKARRAY_H__

class StackArray{
    float* elems;
    int posTop;
    int capacity;

public:
    StackArray(int cap = 10)
        : elems(new float[cap]), posTop(0), capacity(cap) {}
    ~StackArray() {
        delete[] elems;
    }

    int size() {
        return posTop;
    }
    bool is_empty() {
        return posTop == 0;
    }
    bool is_full() {
        return posTop == capacity;
    }

    bool push(float elem) {
        if (posTop < capacity) {
            elems[posTop++] = elem;
            return true;
        }
        return false;
    }
    bool pop() {
        if (posTop > 0) {
            --posTop;
            return true;
        }
        return false;
    }
    float top() {
        if (posTop > 0) {
            return elems[posTop - 1];
        }
        return -0.00001; // No hay nada que retornar :(
    }
};

#endif
