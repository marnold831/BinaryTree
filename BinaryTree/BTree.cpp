#include "BTree.h"


BTree::BTree() {
	root = nullptr;
}
BTree::~BTree() {
	destroyTree();
}
void BTree::insertValue(int value, node* subNode) {
	if (subNode->value == value)
		return;
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
	if (value == subNode->value)
		return subNode;
	bool left = value < subNode->value;
	if (left && subNode->leftNode)
		return findValue(value, subNode->leftNode);
	
	if (!left && subNode->rightNode)
		return findValue(value, subNode->rightNode);
	else {
		
		return nullptr;
	}
}

bool BTree::findValue(int value, node** outNode) {
	if (!outNode)
		return false;
	if (!root)
		return false;
	*outNode = findValue(value, root);
	if (!*outNode)
		return false;
	return true;
}
void BTree::destroyTree(node* subNode) {
	if (subNode) {
		destroyTree(subNode->leftNode);
		destroyTree(subNode->rightNode);
		delete subNode;
	}
}
void BTree::destroyTree() {
	if (!root)
		return;
	destroyTree(root);
}
void BTree::deleteValue(int value) {
	if (root)
		deleteValue(value, findValue(value, root));
}
void BTree::deleteValue(int value, node* subNode) {
	if (!subNode)
		return;
	
	if (value == subNode->value) {
		if (subNode->rightNode) {
			node* minNode = minNodeFromGivenNode(subNode->rightNode);
			if (minNode->rightNode)
				subNode->rightNode->leftNode = minNode->rightNode;
			subNode->value = minNode->value;
			delete minNode;
		}
		
		
		
	}	
}
node* BTree::minNodeFromGivenNode(node* subNode) {
	if (!subNode->leftNode)
		return subNode;
	minNodeFromGivenNode(subNode->leftNode);
}
void BTree::print() {
	if (root) {
		print(root);
		std::cout << "\n" << std::endl;
		return;
	}
	std::cout << "Error! No tree exists" << std::endl;
}
void BTree::print(node* subNode) {
	if (subNode) {
		print(subNode->leftNode);
		std::cout << subNode->value << ", ";
		print(subNode->rightNode);
	}
	return;
}
std::ostream& operator<< (std::ostream& os, const BTree& tree) {
	os << tree.root;
	return os;
}
std::ostream& operator<< (std::ostream& os, const node* node) {
	if (node->leftNode)
		os << node->leftNode;
	os << node->value << ", ";
	if (node->rightNode)
		os << node->rightNode;

	return os;
}