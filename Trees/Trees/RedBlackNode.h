#pragma once
#pragma once
#include<memory>

class RedBlackNode {
public:
	int key;
	std::unique_ptr<RedBlackNode> left = nullptr;
	std::unique_ptr<RedBlackNode> right = nullptr;
	RedBlackNode* parent = nullptr;
	int black = 1;
	bool NIL = false;

	RedBlackNode(int key, RedBlackNode* parent) {
		this->key = key;
		this->parent = parent;
		this->NIL = NIL;
	}
	bool IsLeftChild() {
		return parent->left && parent->left->key == key;
	}
	bool IsRightChild() {
		return parent->right && parent->right->key == key;
	}
	bool IsLeaf() {
		return !right && !left;
	}
	bool IsFourNode() {
		return (left && !left->black && right && !right->black);
	}
	void FlipColor() {
		int temp = black;
		black = left->black;
		left->black = temp;
		right->black = temp;
	}
private:

};