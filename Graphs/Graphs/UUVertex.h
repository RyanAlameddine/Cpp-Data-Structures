#pragma once
#include<vector>

template<typename TValue>
class UUVertex {
public:
	TValue value;
	std::vector<UUVertex> connections;
	void Connect(UUVertex<TValue>*);

private:

};

#include "UUVertex.tpp"