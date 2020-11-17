#include "HashTable.h"
#include <iostream>
#include <string.h>

using namespace std;

template<class K, class V>
void HashTable<K, V>::Resize() {

}

template<class K, class V>
int HashTable<K, V>::Hash(K key) {
	string s = "";
	s = key;
	int multiplier = 0;
	for (int i = 0; i < s.size(); i++)
		multiplier += s[i];

	if (multiplier < 0) multiplier = -multiplier;

	return multiplier % _capacity;
}

template<class K, class V>
int HashTable<K, V>::Probe(int factor) {
	return factor * _lineProbeFactor;
}

template<class K, class V>
void HashTable<K, V>::Add(K key, V value) {
	HashTableNode<K, V> *node = new HashTableNode<K,V>(key, value);

	int hashed = Hash(key);
	int index = hashed;
	int counter = 1;
	HashTableNode<K, V> *current = (nodes + index);
	while (current->isAssigned)
	{
		index = (hashed + Probe(counter)) % _capacity;
		current = (nodes + index);
	}

	node->isAssigned = true;
	*(nodes + index) = *node;
}

template<class K, class V>
void HashTable<K, V>::Remove(K key) {

}

template<class K, class V>
bool HashTable<K, V>::Exists(K key) {

}

template<class K, class V>
V HashTable<K, V>::Get(K key) {

}

template<class K, class V>
HashTable<K, V>::HashTable() {
	nodes = new HashTableNode<K, V>[_capacity];
}

template<class K, class V>
HashTableNode<K, V> HashTable<K, V>::GetAt(int index) {
	return *(nodes + index);
}

int main() { return 0; }