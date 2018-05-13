#pragma once

#include "RedBlackNode.h"
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<array>

class RedBlackTree {
public:
	std::unique_ptr<RedBlackNode> head = nullptr;

	RedBlackNode* GetNode(int key) {
		RedBlackNode* currentNode = head.get();
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

	RedBlackNode* Minimum() {
		RedBlackNode* currentNode = head.get();
		while (currentNode) {
			currentNode = currentNode->left.get();
		}
		return currentNode;
	}

	RedBlackNode* Maximum() {
		RedBlackNode* currentNode = head.get();
		while (currentNode) {
			currentNode = currentNode->right.get();
		}
		return currentNode;
	}

	void Insert(int key) {
		if (!head) {
			head = std::make_unique<RedBlackNode>(key, nullptr);
			return;
		}
		RedBlackNode* currentNode = head.get();
		while (currentNode) {
			if (currentNode->IsFourNode()) {
				currentNode->FlipColor();
			}

			if (key > currentNode->key) {
				if (currentNode->right) {
					currentNode = currentNode->right.get();
					continue;
				}
				currentNode->right = std::make_unique<RedBlackNode>(key, currentNode);
				currentNode->right->black = 0;
				break;
			}
			else {
				if (currentNode->left) {
					currentNode = currentNode->left.get();
					continue;
				}
				currentNode->left = std::make_unique<RedBlackNode>(key, currentNode);
				currentNode->left->black = 0;
				break;
			}
		}
		if (!currentNode) { return; }

		while (currentNode) {
			if (currentNode->right && currentNode->right->black == 0) {
				LeftRotate(currentNode);
			}
			if (currentNode->left && currentNode->left->black == 0 && currentNode->left->left && currentNode->left->left->black == 0) {
				RightRotate(currentNode);
				currentNode = currentNode->parent;
			}
			currentNode = currentNode->parent;
		}
	}

	void Print() {
		if (!head) {
			std::cout << "{ }" << std::endl;
		}
		std::queue<RedBlackNode*> layer;
		layer.push(head.get());
		std::cout << "{ ";
		while (layer.size() > 0) {
			RedBlackNode* removed = layer.front();
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
	void DetailPrint() {

		std::vector<std::vector<RedBlackNode*>> layers;
		int depth = 0;

		std::vector<RedBlackNode*> headLayer;
		headLayer.push_back(head.get());
		layers.push_back(headLayer);
		RedBlackNode* NIL = new RedBlackNode(0, nullptr);
		NIL->NIL = true;
		bool done = false;
		while (!done) {
			done = true;
			std::vector<RedBlackNode*> assemblingLayer;
			for (RedBlackNode* node : layers[layers.size() - 1]) {
				if (node->left) {
					assemblingLayer.push_back(node->left.get());
					done = false;
				}
				else {
					assemblingLayer.push_back(NIL);
				}
				if (node->right) {
					assemblingLayer.push_back(node->right.get());
					done = false;
				}
				else {
					assemblingLayer.push_back(NIL);
				}
			}
			layers.push_back(assemblingLayer);
		}
		for (std::vector<RedBlackNode*> layer : layers) {
			for (RedBlackNode* node : layer) {
				if (node->NIL) {
					std::cout << "| ";
					continue;
				}
				std::cout << node->key << " ";
			}
			std::cout << std::endl;
		}
		delete(NIL);
	}

	bool Delete(int key) {
		RedBlackNode* currentNode = head.get();
		while (currentNode != nullptr) {
			if (key < currentNode->key) {
				//left
				if (currentNode->left && currentNode->left->black == 1 && currentNode->left->left && currentNode->left->left->black == 1) {
					MoveRedLeft(currentNode);
				}
				currentNode = currentNode->left.get();
			}
			else {
				//right
				if (currentNode->left && currentNode->left->black == 0) {
					RightRotate(currentNode);
				}
				if (currentNode->key == key) {
					if (currentNode->IsLeaf()) {
						if (currentNode->IsLeftChild()) {
							currentNode->parent->left = nullptr;
						}
						else {
							currentNode->parent->right = nullptr;
						}
						break;
					}
					else {
						MoveRedRight(currentNode);
						RedBlackNode* minimum = currentNode->right.get();
						while (minimum->left) {
							minimum = minimum->left.get();
						}
						int key = minimum->key;
						Delete(key);
						currentNode->key = key;
						Fixup(currentNode);
						break;
					}
				}
				currentNode = currentNode->right.get();
			}
		}
		return false;

	}
private:
	void Fixup(RedBlackNode* start) {
		if (start->right && start->right->black == 0) {
			LeftRotate(start);
		}
		else if (start->left && start->left->black == 0 && start->left->left && start->left->left->black == 0) {
			RightRotate(start);
		}
		else if (start->right && start->left && start->right->black == 0 && start->left->black == 0) {
			start->FlipColor();
		} else if (!start->left && start->left->right && start->left->right->black == 0 && start->left->left && start->left->left->black == 1)
		{
			LeftRotate(start->left.get());

			start = start->parent;
			if (start->left && start->left->black == 0)
			{
				RightRotate(start);
				start = start->parent;
			}
		}

		if (start->parent) {
			Fixup(start->parent);
		}
	}

	void LeftRotate(RedBlackNode* start) {
		RedBlackNode* toRotate = start->right.get();

		int color = start->black;
		start->black = toRotate->black;
		toRotate->black = color;

		std::unique_ptr<RedBlackNode> temp = nullptr;
		if (toRotate->left) { temp = std::move(toRotate->left); }
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

	void RightRotate(RedBlackNode* start) {
		RedBlackNode* toRotate = start->left.get();

		int color = start->black;
		start->black = toRotate->black;
		toRotate->black = color;

		std::unique_ptr<RedBlackNode> temp = nullptr;
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

	void MoveRedRight(RedBlackNode* start) {
		if (start->left && IsBlack(start->left->left.get())) {
			start->FlipColor();
		}
		if (start->left && !IsBlack(start->left->left.get())) {
			RightRotate(start);
			start->parent->FlipColor();
		}
	}

	void MoveRedLeft(RedBlackNode* start) {
		start->FlipColor();
		if (!IsBlack(start->right->left.get())) {
			RightRotate(start->right.get());
			LeftRotate(start);
			start = start->parent;
			start->FlipColor();
		}
	}

	bool IsBlack(RedBlackNode* start) {
		if (!start) {
			return true;
		}
		else {
			return start->black == 1;
		}
	}
};