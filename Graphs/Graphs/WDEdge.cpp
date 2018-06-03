#include "WDEdge.h"

WDEdge::WDEdge(WDVertex * start, WDVertex * end, int weight){
	this->start = start;
	this->end = end;
	this->weight = weight;
}