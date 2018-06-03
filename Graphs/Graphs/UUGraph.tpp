template<typename TValue>
void UUGraph<TValue>::DepthFirstTraversal(UUVertex start)
{
	std::vector<TValue> read;
	std::stack<UUVertex<TValue>> stack;
	stack.push(start);

	while (stack.size() > 0) {
		UUVertex<TValue> parent = stack.pop();
		for (UUVertex<TValue> vertex : parent.connections) {
			bool contains = false;
			for (UUVertex<TValue> readVertex : read) {
				if (readVertex.value == vertex.value) {
					contains = true;
					break;
				}
			}
			if (!contains) {
				read.push_back(vertex);
				stack.push(vertex);
			}
		}
	}
}

template<typename TValue>
void UUGraph<TValue>::BreadthFirstTraversal(UUVertex start)
{
	std::vector<TValue> read;
	std::queue<UUVertex<TValue>> queue;
	queue.push(start);

	while (stack.size() > 0) {
		UUVertex<TValue> parent = queue.pop();
		for (UUVertex<TValue> vertex : parent.connections) {
			bool contains = false;
			for (UUVertex<TValue> readVertex : read) {
				if (readVertex.value == vertex.value) {
					contains = true;
					break;
				}
			}
			if (!contains) {
				read.push_back(vertex);
				queue.push(vertex);
			}
		}
	}
}