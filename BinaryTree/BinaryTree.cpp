// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BTree.h"


int main()
{
	BTree tree;
	tree.insertValue(10);
	tree.insertValue(9);
	tree.insertValue(9);
	tree.insertValue(11);
	tree.insertValue(8);
	tree.insertValue(12);
	tree.insertValue(1);
	tree.insertValue(7);
	tree.insertValue(15);
	tree.insertValue(13);
	//node* tempNode = new node();
	//node** resultNode = new node*;
	//std::cout << tree.findValue(10, resultNode) << std::endl;
	
	//std::cout << (*resultNode)->value << std::endl;

	//std::cout << tree.findValue(13, resultNode) << std::endl;
	//std::cout << (*resultNode)->value << std::endl;
	tree.deleteValue(13);
	tree.print();
	std::cout << tree << std::endl;
    std::cout << "Hello World!\n";
}

