#pragma once
#include <iostream>

struct node {
	node() : value(0), leftNode(nullptr),  rightNode(nullptr)
	{
		
	}
	node(int value) : value(value), leftNode(nullptr), rightNode(nullptr) {

	}
	friend std::ostream& operator<< (std::ostream& os, const node* node);
	int value;
	node* leftNode;
	node* rightNode;
};

class BTree {
public :
	BTree();
	~BTree();

	void insertValue(int value);
	bool findValue(int value, node** outNode);
	void destroyTree();
	void deleteValue(int value);
	void print();
	friend std::ostream& operator<< (std::ostream& os, const BTree& tree);
private:
	node* root;

	void destroyTree(node* subNode);
	void insertValue(int value, node* subNode);
	node* findValue(int value, node* subNode);
	node* deleteValue(int value, node* subNode);
	node* minNodeFromGivenNode(node* subNode);
	void print(node* subNode);
};


