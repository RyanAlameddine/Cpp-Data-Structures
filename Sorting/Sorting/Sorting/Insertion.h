#pragma once

#include<vector>

void Insertion(std::vector<int>& values) {
	for (int i = 1; i < values.size(); i++) {
		int value = values[i];
		int j = i - 1;
		bool shifted = false;
		for (; j >= 0; j--) {
			if (value > values[j]) {
				values.insert(values.begin() + j + 1, value);
				values.erase(values.begin() + i + 1);
				shifted = true;
				break;
			}
		}
		if (!shifted) {
			values.insert(values.begin(), value);
			values.erase(values.begin() + i + 1);
		}
	}
}

//void Swap(std::vector<int>& values, int first, int last) {
//	int temp = values[first];
//	values[first] = last;
//	values[last] = first;
//}