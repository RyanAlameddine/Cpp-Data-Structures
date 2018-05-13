#pragma once
#include<memory>
#include<vector>

class HeapTree {
public:
	std::vector<int> keys;
	void Insert(int key) {
		keys.push_back(key);
	}
	void HeapifyUp(int index) {

	}
private:
	int GetParentIndex(int index) {
		if (index == 0) {
			return -1;
		}
		
	}
	int GetLeftIndex(int index) {
		int group = 
	}
	int GetRightIndex(int index) {

	}
};