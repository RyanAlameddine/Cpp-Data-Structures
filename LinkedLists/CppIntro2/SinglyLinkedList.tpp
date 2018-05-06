
template<typename T>
std::string SinglyLinkedList<T>::ToString() {
	std::string output = "{ ";

	SinglyLinkedListNode* currentNode = head.get();
	while (currentNode) {
		output += std::to_string(currentNode->data) + ", ";
		currentNode = currentNode->next.get();
	}

	output.pop_back();
	output.pop_back();

	output += " }\n";

	return output;
}

template<typename T>
void SinglyLinkedList<T>::AddLast(int input) {
	std::unique_ptr<SinglyLinkedListNode> inputNode = std::make_unique<SinglyLinkedListNode>(input);
	if (!head) {
		head = std::move(inputNode);
		return;
	}

	SinglyLinkedListNode* currentNode = head.get();
	while (currentNode->next) {
		currentNode = currentNode->next.get();
	}
	currentNode->next = std::move(inputNode);
}