#include<iostream>

#include "AVL.h"

int main() {
	AVL tree;

	tree.Insert(1);
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(2);
	tree.Insert(9);
	tree.Insert(6);
	tree.Insert(3);
	tree.Insert(8);
	tree.Insert(4);

	tree.Print();

	system("PAUSE");
}