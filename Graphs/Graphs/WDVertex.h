#pragma once
#include<vector>
#include<memory>

#include "WDEdge.h"

class WDVertex{
public:
	int value;
	std::vector<std::unique_ptr<WDEdge>> connections;	
	WDVertex(int value);

	void cancelReverseConnections();

	void addReverseConnections(WDVertex* edge);

private:
	std::vector<WDVertex*> connected;
};

