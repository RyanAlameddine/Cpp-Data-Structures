#pragma once
#include "SinglyLinkedListNode.h"
#include <string>

template<typename T>
class SinglyLinkedList{
public:
	std::string ToString();

	void AddLast(int input);

	void AddFirst(int input) {
		std::unique_ptr<SinglyLinkedListNode> inputNode = std::make_unique<SinglyLinkedListNode>(input);
		if (!head) {
			head = std::move(inputNode);
			return;
		}

		inputNode->next = std::move(head);
		head = std::move(inputNode);
	}

	bool Remove(int input) {
		if (head->data == input) {
			auto temp = std::move(head);
			head = std::move(temp->next);
			return true;
		}

		SinglyLinkedListNode* currentNode = head.get();
		while(currentNode->next){
			if (currentNode->next->data == input) {
				SinglyLinkedListNode* temp = currentNode->next.get();
				currentNode->next = std::move(currentNode->next->next);
				temp->next = nullptr;
				return true;
			}
			currentNode = currentNode->next.get();
		}
		return false;
	}

	bool RemoveAt(int index) {
		if(!head){
			return false;
		}
		if (index == 0) {
			head = std::move(head->next);
			return true;
		}

		SinglyLinkedListNode* currentNode = head.get();
		for (int i = 1; i < index; i++) {
			if (!currentNode->next) {
				return false;
			}
			currentNode = currentNode->next.get();
		}

		currentNode->next = std::move(currentNode->next->next);
		return true;
	}

	bool IsEmpty() {
		return !head;
	}

	void Clear() {
		head = nullptr;
	}

	bool Contains(int input) {
		SinglyLinkedListNode* currentNode = head.get();
		while (currentNode) {
			if (currentNode->data == input) {
				return true;
			}
			currentNode = currentNode->next.get();
		}
		return false;
	}

	SinglyLinkedListNode* FindNode(int input) {
		SinglyLinkedListNode* currentNode = head.get();
		while (currentNode) {
			if (currentNode->data == input) {
				return currentNode;
			}
			currentNode = currentNode->next.get();
		}
		return nullptr;
	}

	int Count() {
		SinglyLinkedListNode* currentNode = head.get();
		int i = 0;
		for (; currentNode; i++) {
			currentNode = currentNode->next.get();
		}

		return i;
	}
private:
	std::unique_ptr<SinglyLinkedListNode> head = nullptr;
};

#include "SinglyLinkedList.tpp"