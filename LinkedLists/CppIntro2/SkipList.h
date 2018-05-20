#pragma once

#include<utility>
#include<random>
#include<time.h>
#include<iostream>
#include<limits>

#include "SkipNode.h"

class SkipList {
public:
	SkipNode* head = new SkipNode(0, 1);
	SkipNode* tail = new SkipNode(0, 1);
	SkipList() {
		head->connections.push_back(tail);
	}
	int ChooseRandomHeight() {
		int height = 1;
		while (height <= head->height) {
			if (rand() <= std::numeric_limits<int>::max()/2) {
				height++;
			}
			else {
				break;
			}
		}
		while (height > head->height) {
			head->height++;
			tail->height++;
			head->connections.push_back(tail);
		}
		return height;
	}
	void Insert(int value) {
		int height = ChooseRandomHeight();
		SkipNode* toAdd = new SkipNode(value, height);
		SkipNode* currentNode = head;
		int currentHeight = head->height;
		while (currentHeight >= height) {
			if (currentNode->connections[currentHeight - 1]->value > value) {
				currentNode = currentNode->connections[currentHeight - 1];
			}
			else {
				currentHeight--;
			}
		}
		currentHeight++;
		SkipNode* NodeHit = currentNode->connections[currentHeight - 1];

		for (int i = currentHeight - 1; i >= 0; i--) {

			SkipNode* hitNode = getHitNode(i, NodeHit->value);
			if (hitNode != toAdd) {
				hitNode->connections[i] = toAdd;
			}

			toAdd->connections.push_back(NodeHit);
		}

		currentNode->connections[currentHeight - 1] = toAdd;
	}
	void Delete(int value) {
		SkipNode* currentNode = head;
		int currentHeight = head->height-1;
		while (currentNode->value != value) {
			if (currentNode->connections[currentHeight]->value >= value) {
				currentNode = currentNode->connections[currentHeight];
			}
			else {
				currentHeight--;
			}
		}
		int nodeHeight = currentNode->height;
		for (int i = nodeHeight - 1; i >= 0; i--) {
			getHitNode(i, currentNode->value)->connections[i] = currentNode->connections[i];
		}
		delete(currentNode);
	}
	void Print() {
		SkipNode* currentNode = head;
		while (currentNode != nullptr) {
			std::cout << currentNode->value << ": ";
			for (SkipNode* node : currentNode->connections) {
				std::cout << "|";
			}
			if (currentNode->connections.size() == 0) {
				std::cout << std::endl << std::endl;
				return;
			}
			currentNode = currentNode->connections[0];
			std::cout << std::endl;
		}
	}
private:
	SkipNode* getHitNode(int height, int targetValue) {
		SkipNode* currentNode = head;
		while (true) {
			SkipNode* hit = currentNode->connections[height];
			if (hit->value != targetValue) {
				currentNode = hit;
			}
			else {
				return currentNode;
			}
		}
	}
};