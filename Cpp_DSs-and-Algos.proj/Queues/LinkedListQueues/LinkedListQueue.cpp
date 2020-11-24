#include "LinkedListQueue.h"

#include <iostream>
using namespace std;

template <class T>
void LinkedListQueue<T>::ExitIfEmpty() {
    if (IsEmpty()) {
        std::cout << "Queue IS EMPTY";
        exit(EXIT_FAILURE);
    }
}

template<class T>
int LinkedListQueue<T>::GetSize() {
    return length;
}

template<class T>
bool LinkedListQueue<T>::IsEmpty() {
    return length == 0;
}

template<class T>
void LinkedListQueue<T>::Enqueue(T value) {
    SinglyLinkedNode<T>* newNode = new SinglyLinkedNode<T>(value);

    if (IsEmpty()) Head = newNode;
    else Tail->Next = newNode;

    Tail = newNode;
    length++;
}

template<class T>
T LinkedListQueue<T>::Dequeue() {
    ExitIfEmpty();

    SinglyLinkedNode<T>* oldHead = Head;
    T oldVal = oldHead->value;
    Head = oldHead->Next;
    delete oldHead;

    length--;
    return oldVal;
}