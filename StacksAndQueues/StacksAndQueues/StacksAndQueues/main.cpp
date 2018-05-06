#include<iostream>
#include "Queue.h";

int main() {
	Queue queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Dequeue();

	std::cout << queue.ToString() << std::endl;

	system("PAUSE");
}