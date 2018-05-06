#pragma once

#include "DoublyLinkedListNode.h"
#include <string>

class DoublyLinkedList {
public:
	std::string ToString() {
		std::string output = "{ ";

		DoublyLinkedListNode* currentNode = head.get();
		while (currentNode) {
			output += std::to_string(currentNode->data) + ", ";
			currentNode = currentNode->next.get();
		}

		output.pop_back();
		output.pop_back();

		output += " }\n";

		return output;
	}

	void AddLast(int input) {
		std::unique_ptr<DoublyLinkedListNode> inputNode = std::make_unique<DoublyLinkedListNode>(input);
		if (!head) {
			head = std::move(inputNode);
			return;
		}

		DoublyLinkedListNode* currentNode = head.get();
		while (currentNode->next) {
			currentNode = currentNode->next.get();
		}
		currentNode->next = std::move(inputNode);
		currentNode->next->previous = currentNode;
	}

	void AddFirst(int input) {
		std::unique_ptr<DoublyLinkedListNode> inputNode = std::make_unique<DoublyLinkedListNode>(input);
		if (!head) {
			head = std::move(inputNode);
			return;
		}
		
		inputNode->next = std::move(head);
		head = std::move(inputNode);
		head->next->previous = head.get();
	}

	bool Remove(int input) {
		if (head->data == input) {
			auto temp = std::move(head);
			head = std::move(temp->next);
			if (head->next) {
				head->next->previous = nullptr;
			}
			return true;
		}

		DoublyLinkedListNode* currentNode = head.get();
		while (currentNode->next) {
			if (currentNode->next->data == input) {
				currentNode->next = std::move(currentNode->next->next);
				currentNode->next->previous = currentNode;
				return true;
			}
			currentNode = currentNode->next.get();
		}
		return false;
	}

	bool RemoveAt(int index) {
		if (!head) {
			return false;
		}
		if (index == 0) {
			head = std::move(head->next);
			if (head->next) {
				head->next->previous = head.get();
			}
			return true;
		}

		DoublyLinkedListNode* currentNode = head.get();
		for (int i = 1; i < index; i++) {
			if (!currentNode->next) {
				return false;
			}
			currentNode = currentNode->next.get();
		}

		currentNode->next = std::move(currentNode->next->next);
		currentNode->next->previous = currentNode;
		return true;
	}

	bool IsEmpty() {
		return !head;
	}

	void Clear() {
		head = nullptr;
	}

	bool Contains(int input) {
		DoublyLinkedListNode* currentNode = head.get();
		while (currentNode) {
			if (currentNode->data == input) {
				return true;
			}
			currentNode = currentNode->next.get();
		}
		return false;
	}

	DoublyLinkedListNode* FindNode(int input) {
		DoublyLinkedListNode* currentNode = head.get();
		while (currentNode) {
			if (currentNode->data == input) {
				return currentNode;
			}
			currentNode = currentNode->next.get();
		}
		return nullptr;
	}

	int Count() {
		DoublyLinkedListNode* currentNode = head.get();
		int i = 0;
		for (; currentNode; i++) {
			currentNode = currentNode->next.get();
		}

		return i;
	}
private:
	std::unique_ptr<DoublyLinkedListNode> head = nullptr;
};