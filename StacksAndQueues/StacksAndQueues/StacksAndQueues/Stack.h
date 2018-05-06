#pragma once

#include<memory>
#include<string>
#include "StackNode.h"

class Stack {
public:
	std::string ToString() {
		if (!top) { return "{ }"; }
		StackNode* currentNode = top.get();
		std::string output = "{ ";
		while (currentNode) {
			output += std::to_string(currentNode->value) + ", ";
			currentNode = currentNode->next.get();
		}
		output = output.substr(0, output.length() - 2);
		output += " }";
		return output;
	}

	void Push(int value) {
		if (top) {
			auto temp = std::make_unique<StackNode>(value);
			temp->next = std::move(top);
			top = std::move(temp);
		}
		else {
			top = std::make_unique<StackNode>(value);
		}
	}

	std::unique_ptr<StackNode> Pop() {
		if (!top) {
			return nullptr;
		}
		else {
			auto temp = std::move(top);
			top = std::move(temp->next);
			return temp;
		}
	}

	StackNode* Peek() {
		return top.get();
	}

	bool IsEmpty() {
		return !!top;
	}

	int Count() {
		if (!top) return 0;
		int c = 1;
		StackNode* currentNode = top.get();
		while (currentNode) {
			c++;
			currentNode = currentNode->next.get();
		}
		return c;
	}
private:
	std::unique_ptr<StackNode> top;
};