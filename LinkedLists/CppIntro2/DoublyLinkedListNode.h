#pragma once
#include <memory>

struct DoublyLinkedListNode {
	int data;
	std::unique_ptr<DoublyLinkedListNode> next = nullptr;
	DoublyLinkedListNode* previous = nullptr;

	DoublyLinkedListNode(int data) {
		this->data = data;
	}
};
