#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

template<class T>
void RemoveAtHelper(SinglyLinkedList<T>* lst, int index) {
    SinglyLinkedNode<T>* current = lst->Head;
    SinglyLinkedNode<T>* prev = current;
    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->Next;
    }

    prev->Next = current->Next;
    delete current;
}

template<class T>
bool RemoveConstantTimeIfIndexAllows(SinglyLinkedList<T>* lst, int index) {
    if (index < 0 || index > lst->Length() - 1) throw std::invalid_argument("Given index is not within the bounds of the linked list.");
    if (lst->IsEmpty() == 1) throw std::invalid_argument("Cannot remove from an empty list.");
    if (index == 0) {
        lst->PopFront();
        return true;
    }
    if (index == lst->Length() - 1) {
        lst->PopBack();
        return true;
    }

    return false;
}

template<class T>
T GetLinearTime(SinglyLinkedList<T>* lst, int forLoopCount) {
    SinglyLinkedNode<T>* current = lst->Head;
    for (int i = 0; i < forLoopCount; i++)
    {
        current = current->Next;
    }
    return current->value;
}

template<class T>
T GetConstantTimeIfIndexAllows(SinglyLinkedList<T>* lst, int index) {
    if (index < 0 || index > lst->Length() - 1) throw std::invalid_argument("Given index is not within the bounds of the linked list.");
    if (index == 0) return lst->GetFront();
    if (index == lst->Length() - 1) return lst->GetBack();

    return GetLinearTime(lst, index);
}

template<class T>
int SinglyLinkedList<T>::Length() {
    return length;
}

template<class T>
bool SinglyLinkedList<T>::IsEmpty() {
    return length == 0;
}

template<class T>
void SinglyLinkedList<T>::PushBack(T value) {
    if (IsEmpty() == 1) {
        Head = new SinglyLinkedNode<T>(value);
    }
    else {
        SinglyLinkedNode<T>* tail = Head;
        while (tail->Next)
        {
            tail = tail->Next;
        }

        tail->Next = new SinglyLinkedNode<T>(value);
    }
    length++;
}

template<class T>
void SinglyLinkedList<T>::PushFront(T value) {
    if (IsEmpty() == 1) {
        Head = new SinglyLinkedNode<T>(value);
    }
    else {
        Head = new SinglyLinkedNode<T>(value, Head);
    }

    length++;
}

template<class T>
T SinglyLinkedList<T>::GetFront() {
    if (IsEmpty() == 1) return 0;
    return Head->value;
}

template<class T>
T SinglyLinkedList<T>::GetBack() {
    if (IsEmpty() == 1) return 0;
    SinglyLinkedNode<T>* current = Head;
    while (current->Next) {
        current = current->Next;
    }
    return current->value;
}

template<class T>
void SinglyLinkedList<T>::InsertAt(T value, int index) {
    if (index < 0 || index > length) throw std::invalid_argument("Given index is not within the bounds of the linked list.");
    if (index == 0) {
        PushFront(value);
        return;
    }
    if (index == length)
    {
        PushBack(value);
        return;
    }
    SinglyLinkedNode<T>* current = Head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->Next;
    }

    current->Next = new SinglyLinkedNode<T>(value, current->Next);
    length++;
}

template<class T>
T SinglyLinkedList<T>::GetValueAt(int index) {
    return GetConstantTimeIfIndexAllows(this, index);
}

template<class T>
T SinglyLinkedList<T>::GetValueAtFromEnd(int index) {
    return GetConstantTimeIfIndexAllows(this, length - index - 1);
}

template<class T>
void SinglyLinkedList<T>::Reverse() {
    SinglyLinkedNode<T>* prev;
    SinglyLinkedNode<T>* current = Head;
    SinglyLinkedNode<T>* next = Head->Next;

    current->Next = NULL;

    while (next->Next)
    {
        prev = current;
        current = next;
        next = current->Next;
        current->Next = prev;
    }

    Head = next;
    next->Next = current;
}

template<class T>
T SinglyLinkedList<T>::PopFront() {
    if (IsEmpty() == 1) throw std::invalid_argument("Cannot pop on an empty list.");

    SinglyLinkedNode<T>* formerHead = Head;
    T value = formerHead->value;
    Head = formerHead->Next;

    delete formerHead;
    length--;
    return value;
}

template<class T>
T SinglyLinkedList<T>::PopBack() {
    if (IsEmpty() == 1) throw std::invalid_argument("Cannot pop on an empty list.");

    SinglyLinkedNode<T>* formerTail = Head;
    SinglyLinkedNode<T>* beforeFormerTail = formerTail;
    while (formerTail->Next) {
        beforeFormerTail = formerTail;
        formerTail = formerTail->Next;
    }

    T value = formerTail->value;
    beforeFormerTail->Next = NULL;

    delete formerTail;
    length--;
    return value;
}

template<class T>
void SinglyLinkedList<T>::RemoveAt(int index) {
    if (RemoveConstantTimeIfIndexAllows(this, index) == true) return;
    RemoveAtHelper(this, index);
    length--;
}

template<class T>
void SinglyLinkedList<T>::Remove(T value) {
    if (IsEmpty() == 1) throw std::invalid_argument("Cannot remove from an empty list.");
    SinglyLinkedNode<T>* current = Head;
    for (int i = 0; i < length; i++)
    {
        if (current->value == value)
        {
            RemoveAtHelper(this, i);
            length--;
            return;
        }
        current = current->Next;
    }

    std::cout << "Value: " << value << " not found.";
}