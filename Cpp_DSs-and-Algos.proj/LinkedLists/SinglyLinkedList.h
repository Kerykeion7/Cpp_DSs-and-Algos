#include "SinglyLinkedNode.h"

template<class T>
class SinglyLinkedList {
private:
    int length = 0;

public:
    SinglyLinkedNode<T>* Head;

    int Length();
    bool IsEmpty();
    void PushBack(T value);
    void PushFront(T value);
    void InsertAt(T value, int index);
    void RemoveAt(int index);
    void Remove(T value);
    void Reverse();
    T GetValueAt(int index);
    T GetValueAtFromEnd(int index);
    T PopBack();
    T PopFront();
    T GetFront();
    T GetBack();
};