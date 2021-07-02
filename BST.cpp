#ifndef BST_CPP
#define BST_CPP

#include <iostream>

struct BSTVertex {
	int key;
	BSTVertex *parent;
	BSTVertex *leftChild;
	BSTVertex *rightChild;
};

class BST {
 private:
	BSTVertex *root;

 public:
	BST();
	BST(int key);

	BSTVertex *insert(int key);
	BSTVertex *insert(BSTVertex *currentvertex, int key);
};

BST::BST() {
	root = NULL;
}

BST::BST(int key) {
	insert(key);
}

BSTVertex *BST::insert(BSTVertex *currentVertex, int key) {
	if (!(currentVertex)) {	 // if no vertices exist in tree/subtree yet, insertion point is found
		currentVertex = new BSTVertex;
		currentVertex->key = key;
		currentVertex->parent = currentVertex->leftChild = currentVertex->rightChild = NULL;
	} else if (currentVertex->key < key) {	// search to the right
		currentVertex->rightChild = insert(currentVertex->rightChild, key);
		currentVertex->rightChild->parent = currentVertex;
	} else {	// search to the left
		currentVertex->leftChild = insert(currentVertex->leftChild, key);
		currentVertex->leftChild->parent = currentVertex;
	}

	return currentVertex;	 // return updated BST
}

BSTVertex *BST::insert(int key) {
	return insert(root, key);
}

int main(int argc, char **argv) {
	BST b(20);
	b.insert(15);
	b.insert(3);
	b.insert(18);
	b.insert(42);
	b.insert(50);
	b.insert(39);
}

#endif
