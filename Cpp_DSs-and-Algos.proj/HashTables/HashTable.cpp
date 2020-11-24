#include "HashTable.h"
#include <iostream>
#include <string.h>

using namespace std;

template <class K, class V>
HashTable<K, V>::~HashTable() {
	nodes = NULL;
	delete nodes;
}

template<class K, class V>
void HashTable<K, V>::Resize() {
	_length = 0;
	_capacity *= 2;
	resizeTreshold = (int)(_capacity * (2.0F / 3.0F));

	HashTableNode<K, V>* newNodes = new HashTableNode<K, V>[_capacity];
	HashTableNode<K, V>* oldNodes = nodes;

	nodes = NULL;
	delete[] nodes;

	nodes = newNodes;
	for (size_t i = 0; i < (_capacity / 2); i++)
	{
		if (oldNodes[i].isAssigned) {
			Add(oldNodes[i].Key, oldNodes[i].Value);
		}
	}

	oldNodes = NULL;
	delete [] oldNodes;
}

template<class K, class V>
int HashTable<K, V>::Hash(K key) {
	string s = "";
	s = key;
	int multiplier = 0;
	for (size_t i = 0; i < s.size(); i++)
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
	HashTableNode<K, V> *node = Get(key);
	if (node) {
		node->Value = value;
		return;
	}
	node = new HashTableNode<K, V>(key, value);

	int hashed = Hash(key);
	int index = hashed;
	int counter = 1;
	HashTableNode<K, V> *current = (nodes + index);
	while (current->isAssigned)
	{
		index = (hashed + Probe(counter)) % _capacity;
		current = (nodes + index);
		counter++;
	}

	node->isAssigned = true;
	*(nodes + index) = *node;
	_length++;
	if (_length == resizeTreshold) Resize();
}

template<class K, class V>
void HashTable<K, V>::Remove(K key) {
	HashTableNode<K, V>* current = Get(key);
	if (!current) return;

	current->isAssigned = false;
	current->Key = K();
	current->Value = V();
	current = NULL;
	delete current;
	_length--;
}

template<class K, class V>
bool HashTable<K, V>::Exists(K key) {
	HashTableNode<K, V>* current = Get(key);
	if (current) return true;

	return false;
}

template<class K, class V>
V HashTable<K, V>::GetValue(K key) {
	HashTableNode<K, V> *current = Get(key);
	if (current) return current->Value;

	return V();
}

template<class K, class V>
HashTableNode<K, V>* HashTable<K, V>::Get(K key) {
	int hashed = Hash(key);
	int index = hashed;
	HashTableNode<K, V>* current = (nodes + index);

	int counter = 1;
	while (current->isAssigned)
	{
		if (current->Key == key) return current;

		index = (hashed + Probe(counter)) % _capacity;
		current = (nodes + index);
		counter++;
	}

	return NULL;
}

template<class K, class V>
HashTable<K, V>::HashTable() {
	nodes = new HashTableNode<K, V>[_capacity];
}

template<class K, class V>
HashTableNode<K, V> HashTable<K, V>::GetAt(int index) {
	return *(nodes + index);
}

template<class K, class V>
int HashTable<K, V>::GetSize() {
	return _length;
}

template<class K, class V>
int HashTable<K, V>::GetCapacity() {
	return _capacity;
}

int main() { return 0; }