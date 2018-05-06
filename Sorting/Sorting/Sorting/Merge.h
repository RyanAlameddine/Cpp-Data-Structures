#pragma once

#include<vector>

void Swap(std::vector<int>& values, int first, int last) {
	int temp = values[first];
	values[first] = last;
	values[last] = first;
}

void MergeGroups(std::vector<int>& values, int left, int right)
{
	int middle = left + (right - left) / 2;

	for (int i = 1 + left; i < right; i++) {
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

void Split(std::vector<int>& values, int left, int right) {
	if (right - left > 1)
	{
		int middle = left + (right - left)/2;
		Split(values, left, middle);
		Split(values, middle + 1, right);
		MergeGroups(values, left, right);
	}
	else
	{
		MergeGroups(values, left, right);
	}
}

void Merge(std::vector<int>& values) {
	Split(values, 0, values.size());
}

