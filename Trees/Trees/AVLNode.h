#pragma once
#include<memory>

class AVLNode {
public:
	int key;
	std::unique_ptr<AVLNode> left = nullptr;
	std::unique_ptr<AVLNode> right = nullptr;
	AVLNode* parent = nullptr;
	int height;
	int balance;
	AVLNode(int key, AVLNode* parent) {
		this->key = key;
		this->parent = parent;
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
	int Height() {
		if (IsLeaf()) {
			return 1;
		}
		else {
			int leftHeight = 0;
			if (left) {
				leftHeight = left->Height();
			}
			int rightHeight = 0;
			if (right) {
				rightHeight = right->Height();
			}
			balance = rightHeight - leftHeight;
			if (leftHeight > rightHeight) {
				height = leftHeight;
				return leftHeight + 1;
			}
			else {
				height = rightHeight;
				return rightHeight + 1;
			}
		}
	}
private:

};