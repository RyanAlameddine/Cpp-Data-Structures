#pragma once

#pragma once

#include<memory>
#include<string>
#include "QueueNode.h"

class Queue {
public:
	std::string ToString() {
		if (!front) { return "{ }"; }
		QueueNode* currentNode = front.get();
		std::string output = "{ ";
		while (currentNode) {
			output += std::to_string(currentNode->value) + ", ";
			currentNode = currentNode->behind.get();
		}
		output = output.substr(0, output.length() - 2);
		output += " }";
		return output;
	}

	void Enqueue(int value) {
		if (front) {
			back->behind = std::make_unique<QueueNode>(value);
			back->behind->infront = back;
			back = back->behind.get();
		}
		else {
			front = std::make_unique<QueueNode>(value);
			back = front.get();
		}
	}

	std::unique_ptr<QueueNode> Dequeue() {
		if (!front) {
			return nullptr;
		}
		else {
			auto temp = std::move(front);
			front = std::move(temp->behind);
			front->infront = nullptr;
			return temp;
		}
	}

	QueueNode* Peek() {
		return front.get();
	}

	bool IsEmpty() {
		return !!front;
	}

	int Count() {
		if (!front) return 0;
		int c = 1;
		QueueNode* currentNode = front.get();
		while (currentNode) {
			c++;
			currentNode = currentNode->behind.get();
		}
		return c;
	}
private:
	std::unique_ptr<QueueNode> front;
	QueueNode* back;
};