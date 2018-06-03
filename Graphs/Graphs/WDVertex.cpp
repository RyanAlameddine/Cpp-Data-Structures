#include "WDVertex.h"

WDVertex::WDVertex(int value)
{
	this->value = value;
}

void WDVertex::cancelReverseConnections() {
	for (WDVertex* vertex : connected) {
		for (int i = 0; i < vertex->connections.size(); i++) {
			if (vertex->connections[i]->end == this) {
				vertex->connections.erase(vertex->connections.begin() + i);
			}
		}
	}
}

void WDVertex::addReverseConnections(WDVertex * edge) {
	connected.push_back(edge);
}