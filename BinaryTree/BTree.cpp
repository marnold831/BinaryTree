#include "BTree.h"
#include <iostream>

BTree::BTree() {
	root = nullptr;
}
BTree::~BTree() {
	destroyTree();
}
void BTree::insertValue(int value, node* subNode) {
	bool left = value < subNode->value;

	if (!subNode->leftNode && !subNode->rightNode) {
		node* newLeaf = new node(value);
		if (left)
			subNode->leftNode = newLeaf;
		else
			subNode->rightNode = newLeaf;
		return;
	}

	if (left) {
		if (!subNode->leftNode) {
			subNode->leftNode = new node(value);
			return;
		}
		insertValue(value, subNode->leftNode);
	}
	else {
		if (!subNode->rightNode) {
			subNode->rightNode = new node(value);
			return;
		}
		insertValue(value, subNode->rightNode);
	}
}
void BTree::insertValue(int value) {
	if (!root) {
		node* newLeaf = new node;
		newLeaf->value = value;
		root = newLeaf;
	}
	else {
		insertValue(value, root);
	}

}

node* BTree::findValue(int value, node* subNode) {
	bool left = value < subNode->value;
	if (value == subNode->value)
		return subNode;
	if (left && subNode->leftNode)
		return findValue(value, subNode->leftNode);
	
	if (!left && subNode->rightNode)
		return findValue(value, subNode->rightNode);
	else {
		node* leaf = new node;
		return leaf;
	}
}

bool BTree::findValue(int value) {
	return findValue(value, root)->value;
}
void BTree::destroyTree(node* subNode) {
	if (subNode) {
		destroyTree(subNode->leftNode);
		destroyTree(subNode->rightNode);
		delete subNode;
	}
}
void BTree::destroyTree() {
	destroyTree(root);
}
void BTree::deleteValue(int value, node* subNode) {
	if (value == subNode->value) {
		node* minNode = minNodeFromGivenNode(subNode->rightNode);
		if (minNode->rightNode)
			subNode->rightNode->leftNode = minNode->rightNode;
		subNode->value = minNode->value;
		delete minNode;
	}
	//find value search

}
node* BTree::minNodeFromGivenNode(node* subNode) {
	if (!subNode->leftNode)
		return subNode;
	minNodeFromGivenNode(subNode->leftNode);
}