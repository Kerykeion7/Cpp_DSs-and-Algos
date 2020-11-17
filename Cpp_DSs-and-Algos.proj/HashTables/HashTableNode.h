#pragma once
template<class K, class V>
class HashTableNode {
public:
    K Key;
    V Value;

    HashTableNode<K, V>(K key, V value) {
        Key = key;
        Value = value;
    }
};