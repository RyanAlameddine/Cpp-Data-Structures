#include<iostream>
#include<random>
#include<time.h>
#include<string>
#include<vector>

#include "Quick.h"

void print(std::vector<int> list) {
	std::cout << "{ ";
	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i];
		if (i + 1 < list.size()) {
			std::cout << ", ";
		}
	}
	std::cout << " }" << std::endl;
}

int main() {
	std::vector<int> list { 5, 3, 6, 2, 9, 7, 0, 1, 4, 8 };

	Quick(list);

	print(list);

	system("PAUSE");
}