#pragma once

struct node {
	node() : value(0), leftNode(nullptr),  rightNode(nullptr)
	{
		
	}
	node(int value) : value(value), leftNode(nullptr), rightNode(nullptr) {

	}
	int value;
	node* leftNode;
	node* rightNode;
};

class BTree {
public :
	BTree();
	~BTree();

	void insertValue(int value);
	bool findValue(int value);
	void destroyTree();
	void deleteValue();

private:
	node* root;

	void destroyTree(node* subNode);
	void insertValue(int value, node* subNode);
	node* findValue(int value, node* subNode);
	void deleteValue(int value, node* subNode);
	node* minNodeFromGivenNode(node* subNode);
};