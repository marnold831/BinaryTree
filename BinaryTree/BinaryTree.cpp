// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BTree.h"


int main()
{
	BTree tree;
	tree.insertValue(10);
	tree.insertValue(9);
	tree.insertValue(11);
	tree.insertValue(8);
	tree.insertValue(12);
	tree.insertValue(1);
	tree.insertValue(7);
	tree.insertValue(15);
	tree.insertValue(13);
	std::cout << tree.findValue(10) << std::endl;
	std::cout << tree.findValue(2) << std::endl;
	std::cout << tree.findValue(1) << std::endl;
	std::cout << tree.findValue(13) << std::endl;
    std::cout << "Hello World!\n";
}

