#include <iostream>
#include "DynamicArray.h"

using namespace std;

template<class T>
void DynamicArray<T>::ExitIfIndexOutOfBounds(int index) {
    if (index < 0 || index > Count - 1)
    {
        std::cout << "\nINDEX OUT OF BOUNDS\n";
        exit(EXIT_FAILURE);
    }
}

template<class T>
void DynamicArray<T>::ExitIfArrayIsEmpty() {
    if (IsEmpty()) {
        std::cout << "ARRAY IS EMPTY";
        exit(EXIT_FAILURE);
    }
}

template <class T>
void DynamicArray<T>::Clear() {
    delete items;
    Count = 0;
    Resize();
}

template <class T>
int DynamicArray<T>::Length() {
    return Count;
}

template <class T>
int DynamicArray<T>::Capacity() {
    return _capacity;
}

template <class T>
bool DynamicArray<T>::IsEmpty() {
    return Count == 0;
}

template <class T>
T DynamicArray<T>::GetAt(int index) {
    ExitIfIndexOutOfBounds(index, Count);
    return *(items + index);
}

template <class T>
void DynamicArray<T>::InsertAt(T item, int index) {
    ExitIfIndexOutOfBounds(index, Count);
    Resize();
    T* newItems = new T[_capacity];
    int oldIndex = 0;
    for (int i = 0; i < Count + 1; i++)
    {
        if (i == index) {
            *(newItems + i) = item;
            continue;
        }
        *(newItems + i) = *(items + oldIndex);
        oldIndex++;
    }

    delete items;
    Count++;
    items = newItems;
}

template <class T>
void DynamicArray<T>::Prepend(T item) {
    InsertAt(item, 0);
}

template <class T>
void DynamicArray<T>::RemoveAt(int index) {
    ExitIfArrayIsEmpty(IsEmpty());
    ExitIfIndexOutOfBounds(index, Count);
    Resize();
    T* newItems = new T[_capacity];
    int oldIndex = 0;
    for (int i = 0; i < Count; i++)
    {
        if (i == index) continue;
        *(newItems + oldIndex) = *(items + i);
        oldIndex++;
    }

    delete items;
    Count--;
    items = newItems;
}

template <class T>
int DynamicArray<T>::IndexOf(T item) {
    for (int i = 0; i < Count; i++)
    {
        if (*(items + i) == item) return i;
    }

    return -1;
}

template <class T>
void DynamicArray<T>::Remove(T item) {
    ExitIfArrayIsEmpty(IsEmpty());
    Resize();
    T* newItems = new T[_capacity];
    int oldIndex = 0;
    int oldCount = Count;
    for (int i = 0; i < oldCount; i++)
    {
        if (*(items + i) == item) {
            Count--;
            continue;
        }
        *(newItems + oldIndex) = *(items + i);
        oldIndex++;
    }

    delete items;
    items = newItems;
}

template <class T>
void DynamicArray<T>::Push(T item) {
    Resize();
    *(items + Count) = item;
    Count++;
}

template <class T>
T DynamicArray<T>::Pop() {
    ExitIfArrayIsEmpty(IsEmpty());

    T poppedItem = *(items + Count - 1);
    *(items + Count - 1) = {};
    Count--;
    Resize();
    return poppedItem;
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    delete items;
}

template <class T>
T& DynamicArray<T>::operator[](int index) {
    return items[index];
}

template <class T>
void DynamicArray<T>::operator=(T temp) {
    for (int i = 0; i < Count; i++) {
        items[i] = temp;
    }
}

template <class T>
DynamicArray<T>::DynamicArray() {
    _capacity = _minCapacity;
    items = new T[_capacity];
}

template <class T>
DynamicArray<T>::DynamicArray(int capacity) {
    if (capacity < _minCapacity)
    {
        _capacity = _minCapacity;
    }
    else
    {
        _capacity = capacity;
    }

    delete items;
    items = new T[_capacity];
}

template <class T>
void DynamicArray<T>::Resize() {
    if (Count == _capacity) {
        AllocateNewCapacity(_capacity * 2);
    }
    else if (Count <= (_capacity / 4)) {
        if ((_capacity / 2) >= _minCapacity) {
            AllocateNewCapacity(_capacity / 2);
        }
    }
}

template<class T>
void DynamicArray<T>::AllocateNewCapacity(int newCapacity) {
    _capacity = newCapacity;
    T* newItems = new T[_capacity];
    for (int i = 0; i < Count; i++)
    {
        *(newItems + i) = *(items + i);
    }
    delete items;
    items = newItems;
}