#pragma once

#include <memory>

struct SinglyLinkedListNode {
	int data;
	std::unique_ptr<SinglyLinkedListNode> next = nullptr;

	SinglyLinkedListNode(int data) {
		this->data = data;
	}
};
