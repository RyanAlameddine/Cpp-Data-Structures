#pragma once
#include<functional>
#include<array>
#include<memory>

template<typename TKey, typename TValue>
class HashMap {
public:
	TValue Get(TKey key) {
		int index = std::hash<TKey>(key) % buckets.size;
	}
	void Replace(TKey key, TValue value) {

	}
	void Insert(TKey key, TValue value) {
		int index = std::hash<TKey>(key) % buckets.size;
		HashEntry<TKey, TValue>* currentEntry = buckets[index].get();
		if (!currentEntry) {
			buckets[index] = std::make_unique<HashEntry<TKey, TValue>>(key, value);
		}
		else {
			while (currentEntry->Next) {
				currentEntry = currentEntry->Next;
			}
			currentEntry->Next = std::make_unique<HashEntry<TKey, TValue>>(key, value);
		}
	}
	void Remove(TKey key) {

	}
private:
	std::array<std::unique_ptr<HashEntry<TKey, TValue>>, 256> buckets;
};

template<typename TKey, typename TValue>
class HashEntry {
public:
	TKey key;
	TValue value;
	std::unique_ptr<HashEntry<TKey, TValue>> Next = nullptr;
	HashEntry(TKey key, TValue value) {
		this->key = key;
		this->value = value;
	}
private:

};