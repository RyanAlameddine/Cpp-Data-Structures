#pragma once
#include<functional>
#include<array>
#include<memory>


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

template<typename TKey, typename TValue>
class HashMap {
public:
	TValue Get(TKey key) {
		size_t index = std::hash<TKey>{}(key) % buckets.size();

		HashEntry<TKey, TValue>* currentEntry = buckets[index].get();
		while (currentEntry->key != key) {
			currentEntry = currentEntry->Next.get();
		}
		return currentEntry->value;
	}
	void Replace(TKey key, TValue value) { 
		size_t index = std::hash<TKey>{}(key) % buckets.size();

		HashEntry<TKey, TValue>* currentEntry = buckets[index].get();
		while (currentEntry->key != key) {
			currentEntry = currentEntry->Next.get();
		}
		currentEntry->value = value;
	}
	void Insert(TKey key, TValue value) {
		size_t index = std::hash<TKey>{}(key) % buckets.size();
		HashEntry<TKey, TValue>* currentEntry = buckets[index].get();
		if (!currentEntry) {
			buckets[index] = std::make_unique<HashEntry<TKey, TValue>>(key, value);
		}
		else {
			while (currentEntry->Next) {
				currentEntry = currentEntry->Next.get();
			}
			currentEntry->Next = std::make_unique<HashEntry<TKey, TValue>>(key, value);
		}
	}
	void Remove(TKey key) {
		size_t index = std::hash<TKey>{}(key) % buckets.size();

		HashEntry<TKey, TValue>* currentEntry = buckets[index].get();
		if (currentEntry->key == key) {
			buckets[index] = std::move(buckets[index]->Next);
			return;
		}
		while (currentEntry->Next->key != key) {
			currentEntry = currentEntry->Next.get();
		}
		currentEntry->Next = std::move(currentEntry->Next->Next);
	}
private:
	std::array<std::unique_ptr<HashEntry<TKey, TValue>>, 256> buckets;
};
