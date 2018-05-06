#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <vector>
#include "SinglyLinkedList.h"
#include <algorithm>
#include <array>
#include <list>

using namespace std;

int main() {
	SinglyLinkedList<int> list;
	list.AddLast(5);
	list.AddLast(6);
	list.AddLast(7);
	list.AddLast(8);
	list.AddFirst(4);
	list.AddFirst(3);
	list.AddFirst(2);
	list.AddFirst(1);

	cout << list.ToString();

	list.RemoveAt(5);

	cout << list.ToString();
	
	cout << list.Count() << std::endl;


	system("PAUSE");
}
