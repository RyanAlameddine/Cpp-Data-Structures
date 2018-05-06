#pragma once
#include<vector>

void Swap(std::vector<int>& values, int first, int last) {
	int temp = values[first];
	values[first] = values[last];
	values[last] = temp;
}

int partition(std::vector<int>& values, int low, int high)
{
	int pivot = values[low];
	int i = low - 1;
	int j = high + 1;
	while (true)
	{
		do
		{
			i += 1;
		} while (values[i] < pivot);
		do
		{
			j -= 1;
		} while (values[j] > pivot);

		if (i >= j) return j;
		Swap(values, i, j);
	}
}

void sort(std::vector<int>& values, int low, int high) {
	if (low < high)
	{
		int p = partition(values, low, high);
		sort(values, low, p);
		sort(values, p + 1, high);
	}
}

void Quick(std::vector<int>& values) {
	sort(values, 0, values.size() - 1);
}