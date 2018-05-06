#pragma once

#include<vector>

void Selection(std::vector<int>& values) {
	for (int i = 0; i < values.size() - 1; i++) {
		int lowestIndex = i;
		for (int j = i + 1; j < values.size(); j++) {
			if (values[j] < values[lowestIndex]) {
				lowestIndex = j;
			}
		}
		int temp = values[i];
		values[i] = values[lowestIndex];
		values[lowestIndex] = temp;
	}
}