#pragma once
#include<memory>

class StackNode {
public:
	int value;
	std::unique_ptr<StackNode> next = nullptr;

	StackNode(int value) {
		this->value = value;
	}
};