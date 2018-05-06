#pragma once

#include "AVLNode.h"
#include<iostream>
#include<vector>
#include<string>
#include<queue>

class AVL {
public:
	std::unique_ptr<AVLNode> head = nullptr;

	AVLNode* GetNode(int key) {
		AVLNode* currentNode = head.get();
		while (currentNode) {
			if (key == currentNode->key) {
				return currentNode;
			}
			if (key > currentNode->key) {
				currentNode = currentNode->right.get();
			}
			else {
				currentNode = currentNode->left.get();
			}
		}
	}

	AVLNode* Minimum() {
		AVLNode* currentNode = head.get();
		while (currentNode) {
			currentNode = currentNode->left.get();
		}
		return currentNode;
	}

	AVLNode* Maximum() {
		AVLNode* currentNode = head.get();
		while (currentNode) {
			currentNode = currentNode->right.get();
		}
		return currentNode;
	}

	void Insert(int key) {
		if (!head) {
			head = std::make_unique<AVLNode>(key, nullptr);
			return;
		}
		AVLNode* currentNode = head.get();
		while (true) {
			if (key < currentNode->key) {
				if (currentNode->left) {
					currentNode = currentNode->left.get();
				}
				else {
					currentNode->left = std::make_unique<AVLNode>(key, currentNode);
					while (currentNode) {
						Rebalance(currentNode);
						currentNode = currentNode->parent;
					}
					return;
				}
			}
			else {
				if (currentNode->right) {
					currentNode = currentNode->right.get();
				}
				else {
					currentNode->right = std::make_unique<AVLNode>(key, currentNode);
					while (currentNode) {
						Rebalance(currentNode);
						currentNode = currentNode->parent;
					}
					return;
				}
			}
		}
	}

	void Print() {
		if (!head) {
			std::cout << "{ }" << std::endl;
		}
		std::queue<AVLNode*> layer;
		layer.push(head.get());
		std::cout << "{ ";
		while (layer.size() > 0) {
			AVLNode* removed = layer.front();
			layer.pop();
			if (removed->left) {
				layer.push(removed->left.get());
			}
			if (removed->right) {
				layer.push(removed->right.get());
			}
			if (layer.size() == 0) {
				std::cout << removed->key;
			}
			else {
				std::cout << removed->key << ", ";
			}
		}
		std::cout << " }" << std::endl;
	}

	bool Delete(int key) {
		AVLNode* currentNode = head.get();
		while (currentNode) {
			if (key == currentNode->key) {
				Delete(currentNode);
			}
			if (key > currentNode->key) {
				currentNode = currentNode->right.get();
			}
			else {
				currentNode = currentNode->left.get();
			}
		}
		return false;
	}
private:
	bool Delete(AVLNode* currentNode) {
		if (!currentNode->left && !currentNode->right) {
			if (currentNode->IsLeftChild()) {
				currentNode->parent->left = nullptr;
				currentNode = currentNode->parent;
				while (currentNode) {
					Rebalance(currentNode);
					currentNode = currentNode->parent;
				}
			}
			else {
				currentNode->parent->right = nullptr;
				currentNode = currentNode->parent;
				while (currentNode) {
					Rebalance(currentNode);
					currentNode = currentNode->parent;
				}
			}
		}
		else if (currentNode->left && currentNode->right) {
			AVLNode* mostSuitable = currentNode->left.get();
			while (mostSuitable->right) {
				mostSuitable = mostSuitable->right.get();
			}
			currentNode->key = mostSuitable->key;
			Delete(mostSuitable);
			while (currentNode) {
				Rebalance(currentNode);
				currentNode = currentNode->parent;
			}
		}
		else if (!currentNode->left && currentNode->right) {
			if (currentNode->IsLeftChild()) {
				currentNode->parent->left = std::move(currentNode->right);
				currentNode = currentNode->parent;
				while (currentNode) {
					Rebalance(currentNode);
					currentNode = currentNode->parent;
				}
			}
			else {
				currentNode->parent->right = std::move(currentNode->right);
				currentNode = currentNode->parent;
				while (currentNode) {
					Rebalance(currentNode);
					currentNode = currentNode->parent;
				}
			}
		}
		else {
			if (currentNode->IsLeftChild()) {
				currentNode->parent->left = std::move(currentNode->left);
				currentNode = currentNode->parent;
				while (currentNode) {
					Rebalance(currentNode);
					currentNode = currentNode->parent;
				}
			}
			else {
				currentNode->parent->right = std::move(currentNode->left);
				currentNode = currentNode->parent;
				while (currentNode) {
					Rebalance(currentNode);
					currentNode = currentNode->parent;
				}
			}
		}
		return true;
	}

	void Rebalance(AVLNode* start) {
		start->Height();
		if (start->balance > 1) {
			if (start->right->balance < 0) {
				Left(start->right.get());
				Right(start);
			}
			else {
				Right(start);
			}
		}
		else if (start->balance < -1) {
			if (start->left->balance > 0) {
				Right(start->left.get());
				Left(start);
			}
			else {
				Left(start);
			}
		}
	}

	void Right(AVLNode* start) {
		AVLNode* toRotate = start->right.get();
		std::unique_ptr<AVLNode> temp = nullptr;
		if(toRotate->left) { temp = std::move(toRotate->left); }
		if (start->key == head->key) {
			toRotate->left = std::move(head);
			head = std::move(start->right);
			head->parent = nullptr;
		}
		else {
			if (start->IsLeftChild()) {
				toRotate->left = std::move(start->parent->left);
				start->parent->left = std::move(start->right);
				toRotate->parent = start->parent;
			}
			else {
				toRotate->left = std::move(start->parent->right);
				start->parent->right = std::move(start->right);
				toRotate->parent = start->parent;
			}
		}
		start->parent = toRotate;
		if (temp) { start->right = std::move(temp); }
	}

	void Left(AVLNode* start) {
		AVLNode* toRotate = start->left.get();
		std::unique_ptr<AVLNode> temp = nullptr;
		if (toRotate->right) { temp = std::move(toRotate->right); }
		if (start->key == head->key) {
			toRotate->right = std::move(head);
			head = std::move(start->left);
			head->parent = nullptr;
		}
		else {
			if (start->IsLeftChild()) {
				toRotate->right = std::move(start->parent->left);
				start->parent->left = std::move(start->left);
				toRotate->parent = start->parent;
			}
			else {
				toRotate->right = std::move(start->parent->right);
				start->parent->right = std::move(start->left);
				toRotate->parent = start->parent;
			}
		}
		start->parent = toRotate;
		if (temp) { start->left = std::move(temp); }
	}
};