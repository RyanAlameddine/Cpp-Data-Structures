#pragma once
#include<memory>
#include<vector>

// PAss all refs by const ref
// Pass any outs by pointer

class HeapTree {
public:
	std::vector<int> keys;
	void Insert(int key) {
		keys.push_back(key);
		HeapifyUp(keys.size() - 1);
	}
	void HeapifyUp(int index) {
		if (index == 0) {
			return;
		}
		int parentIndex = GetParentIndex(index);
		if (keys[index] > keys[parentIndex]) {
			Swap(index, parentIndex);
		}
		HeapifyUp(parentIndex);
	}
private:
	int GetParentIndex(int index) {
		if (index == 0) {
			return -1;
		}
		int indexInGroup;
		int group = GetGroup(index, &indexInGroup);
		
		return std::pow(2, group - 1) + std::ceil(((double)(indexInGroup))/2) - 2;
	}
	int GetLeft(int index) {
		int indexInGroup;
		int group = GetGroup(index, &indexInGroup);
		int newIndexInGroup = indexInGroup * 2 - 1;

		return std::pow(2, group) + newIndexInGroup;
	}
	int GetRight(int index) {
		int indexInGroup;
		int group = GetGroup(index, &indexInGroup);
		int newIndexInGroup = indexInGroup * 2;

		return std::pow(2, group) + newIndexInGroup;
	}
	int GetGroup(int index, int* indexInGroup) {
		int currentIndex = 1;
		int group = 0;
		while (currentIndex < index) {
			group++;
			currentIndex += std::pow(2, group);
		}
		*indexInGroup = index - std::pow(2, group) + 2;
		return group;
	}
	void Swap(int I1, int I2) {
		int temp = keys[I1];
		keys[I1] = keys[I2];
		keys[I2] = temp;
	}
};