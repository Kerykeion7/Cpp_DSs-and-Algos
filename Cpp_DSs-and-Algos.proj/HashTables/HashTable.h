#pragma once
#include "HashTableNode.h"

template<class K, class V>
class HashTable {
private:
    int _length = 0;
    int _capacity = 10;
    int _lineProbeFactor = 1;
    int resizeTreshold = (int)(_capacity * (2.0F / 3.0F));
    HashTableNode<K, V>* nodes;

    void Resize();
    int Probe(int factor);

public:
    ~HashTable();

    HashTable();
    int Hash(K key);
    int GetSize();
    int GetCapacity();
    void Add(K key, V value);
    void Remove(K key);
    HashTableNode<K, V> GetAt(int index);
    HashTableNode<K, V>* Get(K key);
    bool Exists(K key);
    V GetValue(K key);
};