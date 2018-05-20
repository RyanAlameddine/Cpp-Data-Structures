#pragma once

#include<vector>
#include<memory>

class SkipNode {
public:
	int height;
	std::vector<SkipNode*> connections;
	int value;

	SkipNode(int value, int height) {
		this->value = value;
		this->height = height;
	}

	int GetAttachment(int height) {
		height--;
		if (height >= connections.size()) {
			return -1;
		}
		return connections[height]->value;
	}
private:
	
};