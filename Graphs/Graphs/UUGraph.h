#pragma once
#include "UUVertex.h";
#include<stack>
#include<queue>

template<typename TValue>
class UUGraph {
public:
	std::vector<UUVertex<TValue>> vectors;
	UUGraph(TValue start) {
		UUVertex<TValue> startVertex;
		startVertex.value = start;
		vectors.push_back(startVertex);
	}
	void DepthFirstTraversal(UUVertex<TValue> start);

	void BreadthFirstTraversal(UUVertex<TValue> start);
private:

};

#include "UUGraph.h";