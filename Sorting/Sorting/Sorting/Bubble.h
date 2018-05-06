#pragma once
#include<vector>

void Bubble(std::vector<int>& values) {
	bool success = false;
	while (!success) {
		success = true;
		for (int i = 0; i < values.size() - 1; i++) {
			if (values[i] > values[i + 1]) {
				success = false;
				int temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
			}
		}
	}
}