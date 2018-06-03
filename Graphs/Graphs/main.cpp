#include<iostream>
#include<string>
#include"WDGraph.h"
#include <memory>
int main() {
	WDGraph graph;

	WDVertex* zero = graph.addVertex(0);
	WDVertex* one = graph.addVertex(1);
	WDVertex* two = graph.addVertex(2);
	WDVertex* three = graph.addVertex(3);
	WDVertex* four = graph.addVertex(4);
	WDVertex* five = graph.addVertex(5);
	WDVertex* six = graph.addVertex(6);
	WDVertex* seven = graph.addVertex(7);

	graph.connect(three, five, 7);
	graph.connect(five, one, 4);
	graph.connect(seven, five, 4);
	graph.connect(zero, one, 7);
	graph.connect(one, two, 1);
	graph.connect(one, six, 6);
	graph.connect(six, four, 1);
	graph.connect(zero, two, 1);
	graph.connect(two, zero, 7);
	graph.connect(zero, four, 2);
	graph.connect(four, seven, 5);

	graph.Dijkstra(zero, five);

	std::system("PAUSE");
}