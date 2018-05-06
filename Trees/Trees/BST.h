#pragma once

#include "BSTNode.h"
#include<iostream>
#include<vector>
#include<string>
#include<queue>

class BST{
public:
	std::unique_ptr<BSTNode> head = nullptr;
	BSTNode* GetNode(int key) {
		BSTNode* currentNode = head.get();
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
	BSTNode* Minimum() {
		BSTNode* currentNode = head.get();
		while (currentNode) {
			currentNode = currentNode->left.get();
		}
		return currentNode;
	}
	BSTNode* Maximum() {
		BSTNode* currentNode = head.get();
		while (currentNode) {
			currentNode = currentNode->right.get();
		}
		return currentNode;
	}
	void Insert(int key) {
		if (!head) {
			head = std::make_unique<BSTNode>(key, nullptr);
			return;
		}
		BSTNode* currentNode = head.get();
		while (true) {
			if (key < currentNode->key) {
				if (currentNode->left) {
					currentNode = currentNode->left.get();
				}
				else {
					currentNode->left = std::make_unique<BSTNode>(key, currentNode);
					return;
				}
			}
			else {
				if (currentNode->right) {
					currentNode = currentNode->right.get();
				}
				else {
					currentNode->right = std::make_unique<BSTNode>(key, currentNode);
					return;
				}
			}
		}
	}
	void Print() {
		if (!head) {
			std::cout << "{ }" << std::endl;
		}
		std::queue<BSTNode*> layer;
		layer.push(head.get());
		std::cout << "{ ";
		while (layer.size() > 0) {
			BSTNode* removed = layer.front();
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
		BSTNode* currentNode = head.get();
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
	bool Delete(BSTNode* currentNode) {
		if (!currentNode->left && !currentNode->right) {
			if (currentNode->IsLeftChild()) {
				currentNode->parent->left = nullptr;
			}
			else {
				currentNode->parent->right = nullptr;
			}
		}
		else if (currentNode->left && currentNode->right) {
			BSTNode* mostSuitable = currentNode->left.get();
			while (mostSuitable->right) {
				mostSuitable = mostSuitable->right.get();
			}
			currentNode->key = mostSuitable->key;
			Delete(mostSuitable);
		}
		else if (!currentNode->left && currentNode->right) {
			if (currentNode->IsLeftChild()) {
				currentNode->parent->left = std::move(currentNode->right);
			}
			else {
				currentNode->parent->right = std::move(currentNode->right);
			}
		}
		else {
			if (currentNode->IsLeftChild()) {
				currentNode->parent->left = std::move(currentNode->left);
			}
			else {
				currentNode->parent->right = std::move(currentNode->left);
			}
		}
		return true;
	}
};