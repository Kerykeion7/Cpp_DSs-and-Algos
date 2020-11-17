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

    void resize();
    int hash(K key);
    int probe(int factor);

public:
    HashTable() {};
    void add(K key, V value);
    void remove(K key);
    bool exists(K key);
    V get(K key);
};