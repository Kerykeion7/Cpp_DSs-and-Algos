#include "ArrayQueue.h"

#include <iostream>
using namespace std;

template<class T>
bool ArrayQueue<T>::IsEmpty() {
    return length == 0;
}

template<class T>
bool ArrayQueue<T>::IsFull() {
    return length == maxCap;
}

template<class T>
int ArrayQueue<T>::Length() {
    return length;
}

template<class T>
T& ArrayQueue<T>::operator[](int index) {
    return *(data + index);
}

template<class T>
void ArrayQueue<T>::Enqueue(T value) {
    if (IsFull())
    {
        std::cout << "Cannot enqueue because the queue is full.\n";
        exit(EXIT_FAILURE);
    }

    *(data + length) = value;
    length++;
}

template<class T>
T ArrayQueue<T>::Dequeue() {
    if (IsEmpty())
    {
        std::cout << "Cannot dequeue because the queue is empty.\n";
        exit(EXIT_FAILURE);
    }

    T oldVal = *data;
    length--;
    T* newData = new T[maxCap];
    for (int i = 0; i < maxCap; i++)
    {
        if (i == length) break;
        *(newData + i) = *(data + i + 1);
    }
    delete data;
    data = newData;

    return oldVal;
}