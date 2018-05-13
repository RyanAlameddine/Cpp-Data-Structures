#include<iostream>

#include "RedBlackTree.h"

int main() {
	RedBlackTree tree;

	tree.Insert(1);
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(2);
	tree.Insert(3);
	tree.Insert(4);
	tree.Insert(9);
	tree.Insert(8);
	tree.Delete(1);

	tree.Print();
	tree.DetailPrint();

	system("PAUSE");
}