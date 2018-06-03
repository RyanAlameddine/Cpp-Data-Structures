#pragma once
#include<vector>
#include "WDVertex.h"
#include "WDEdge.h"
#include<unordered_map>
#include<limits>
#include<iostream>
#include<string>

class WDGraph{
public:
	std::vector<std::unique_ptr<WDVertex>> verticies;
	WDVertex* addVertex(int value);
	void connect(WDVertex* start, WDVertex* end, int weight);
	void remove(WDVertex* toRemove);
	void Dijkstra(WDVertex* start, WDVertex* end);
private:
};

