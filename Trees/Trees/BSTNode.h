#pragma once
#include<memory>

class BSTNode {
public:
	int key;
	std::unique_ptr<BSTNode> left = nullptr;
	std::unique_ptr<BSTNode> right = nullptr;
	BSTNode* parent = nullptr;
	BSTNode(int key, BSTNode* parent) {
		this->key = key;
		this->parent = parent;
	}
	bool IsLeftChild() {
		return parent->left->key == key;
	}
	bool IsRightChild() {
		return parent->right->key == key;
	}
private:

};