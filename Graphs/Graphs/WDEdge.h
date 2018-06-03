#pragma once

class WDVertex;

class WDEdge{
public:
	int weight;
	WDVertex* start;
	WDVertex* end;
	WDEdge(WDVertex* start, WDVertex* end, int weight);
};