#include "SinglyLinkedNode.h"

template<class T>
class LinkedListQueue {
private:
    int length = 0;
    void ExitIfEmpty();
public:
    SinglyLinkedNode<T>* Head = NULL;
    SinglyLinkedNode<T>* Tail = NULL;

    bool IsEmpty();
    int GetSize();
    void Enqueue(T value);
    T Dequeue();
};
