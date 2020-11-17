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
    int Hash(K key);
    int Probe(int factor);

public:
    HashTable();
    void Add(K key, V value);
    void Remove(K key);
    bool Exists(K key);
    V Get(K key);
};