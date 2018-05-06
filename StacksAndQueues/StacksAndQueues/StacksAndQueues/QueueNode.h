#pragma once
#include<memory>

class QueueNode {
public:
	int value;
	std::unique_ptr<QueueNode> behind = nullptr;
	QueueNode* infront = nullptr;

	QueueNode(int value) {
		this->value = value;
	}
};