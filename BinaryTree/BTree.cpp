#include "BTree.h"

template <typename T>
BTree<T>::BTree() {
	root = nullptr;
}

template <typename T>
BTree<T>::~BTree() {
	destroyTree();
}

template <typename T>
void BTree<T>::insertValue(T value, node<T>* subNode) {
	if (subNode->value == value)
		return;
	bool left = value < subNode->value;

	if (!subNode->leftNode && !subNode->rightNode) {
		node<T>* newLeaf = new node<T>(value);
		if (left)
			subNode->leftNode = newLeaf;
		else
			subNode->rightNode = newLeaf;
		return;
	}

	if (left) {
		if (!subNode->leftNode) {
			subNode->leftNode = new node<T>(value);
			return;
		}
		insertValue(value, subNode->leftNode);
	}
	else {
		if (!subNode->rightNode) {
			subNode->rightNode = new node<T>(value);
			return;
		}
		insertValue(value, subNode->rightNode);
	}
}

template <typename T>
void BTree<T>::insertValue(T value) {
	if (!root) {
		node<T>* newLeaf = new node<T>;
		newLeaf->value = value;
		root = newLeaf;
	}
	else {
		insertValue(value, root);
	}

}

template <typename T>
node<T>* BTree<T>::findValue(T value, node<T>* subNode) {
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

template <typename T>
bool BTree<T>::findValue(T value, node<T>** outNode) {
	if (!outNode)
		return false;
	if (!root)
		return false;
	*outNode = findValue(value, root);
	if (!*outNode)
		return false;
	return true;
}

template <typename T>
void BTree<T>::destroyTree(node<T>* subNode) {
	if (subNode) {
		destroyTree(subNode->leftNode);
		destroyTree(subNode->rightNode);
		delete subNode;
	}
}

template <typename T>
void BTree<T>::destroyTree() {
	if (!root)
		return;
	destroyTree(root);
}

template <typename T>
void BTree<T>::deleteValue(T value) {
	if (root)
		deleteValue(value, root);
}

template <typename T>
node<T>* BTree<T>::deleteValue(T value, node<T>* subNode) {
	if (value < subNode->value)
		subNode->leftNode = deleteValue(value, subNode->leftNode);
	else if (value > subNode->value)
		subNode->rightNode = deleteValue(value, subNode->rightNode);

	if (value == subNode->value) {
		if (!subNode->leftNode) {
			node<T>* temp = subNode->rightNode;
			delete subNode;
			return temp;
		}
		if (!subNode->rightNode) {
			node<T>* temp = subNode->leftNode;
			delete subNode;
			return temp;
		}
		node<T>* temp = minNodeFromGivenNode(subNode->rightNode);
		subNode->value = temp->value;
		subNode->rightNode = deleteValue(temp->value, subNode->rightNode);
	}
	return subNode;


}

template <typename T>
node<T>* BTree<T>::minNodeFromGivenNode(node<T>* subNode) {
	if (!subNode->leftNode)
		return subNode;
	minNodeFromGivenNode(subNode->leftNode);
}

template <typename T>
void BTree<T>::print() {
	if (root) {
		print(root);
		std::cout << "\n" << std::endl;
		return;
	}
	std::cout << "Error! No tree exists" << std::endl;
}

template <typename T>
void BTree<T>::print(node<T>* subNode) {
	if (subNode) {
		print(subNode->leftNode);
		std::cout << subNode->value << ", ";
		print(subNode->rightNode);
	}
	return;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const BTree<T>& tree) {
	os << tree.root;
	return os;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const node<T>* node) {
	if (node->leftNode)
		os << node->leftNode;
	os << node->value << ", ";
	if (node->rightNode)
		os << node->rightNode;

	return os;
}

template std::ostream& operator<<(std::ostream& os, const BTree<int>& tree);
template class BTree<int>;