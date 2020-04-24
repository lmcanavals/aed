#ifndef __QUEUEARRAY_H__
#define __QUEUEARRAY_H__

class QueueArray {
    float* elements;
    int    posFront;
    int    posBack;
    int    capacity;
    int    length;
public:
    QueueArray(int cap=10)
        : elements(new float[cap]), posFront(0), posBack(0),
          capacity(cap), length(0) {}
    ~QueueArray() {
        delete[] elements;
    }
    int size() {
        return length;
    }
    bool is_empty() {
        return length == 0;
    }
    bool is_full() {
        return length == capacity;
    }
    bool push(float elem) {
        if (length < capacity) {
            elements[posBack++] = elem;
            posBack %= capacity;
            ++length;
            return true;
        }
        return false;
    }
    bool pop() {
        if (length > 0) {
            posFront = ++posFront % capacity;
            --length;
            return true;
        }
        return false;
    }
    float front() {
        if (length > 0) {
            return elements[posFront];
        }
        return -0.0001;
    }
};


#endif
