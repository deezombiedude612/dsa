#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;

typedef Node *treeNodePtr;
void insertNode(treeNodePtr *treePtr, int value);
void infix(treeNodePtr treePtr);
void prefix(treeNodePtr treePtr);
void postfix(treeNodePtr treePtr);

int main(int argc, char ** argv) {
	unsigned int i;					/* counter to loop from 1-10 */
	int item;						/* variable to hold random values */
	treeNodePtr rootPtr = NULL;		/* tree initially empty */

	srand(time(NULL));
	printf("The numbers being placed in the tree are: ");

	/* insert random values between 0 and 14 in the tree */
	for(i = 0; i < 10; i++) {
		item = rand() % 15;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}

	/* traverse the tree prefix order */
	printf("\n\nThe prefix traversal is: ");
	prefix(rootPtr);

	/* traverse the tree infix order */
	printf("\n\nThe infix traversal is: ");
	infix(rootPtr);

	/* traverse the tree postfix order */
	printf("\n\nThe postfix traversal is: ");
	postfix(rootPtr);

	printf("\n");

	return 0;
}

/* insert node into tree */
void insertNode(treeNodePtr *treePtr, int value) {
	if(*treePtr == NULL) {		/* if tree is empty */
		*treePtr = malloc(sizeof(Node));

		/* if memory was allocated, then assign data */
		if(*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->left = NULL;
			(*treePtr)->right = NULL;
		} else printf("%d not inserted. No memory available.\n", value);
	} else {					/* tree is not empty */
		if(value < (*treePtr)->data) insertNode(&((*treePtr)->left), value);
		else if(value > (*treePtr)->data) insertNode(&((*treePtr)->right), value);
		else printf("%s", "dup");	/* duplicate data value ignored */
	}
}

/* begin infix order traversal of tree */
void infix(treeNodePtr treePtr) {
	if(treePtr != NULL) {	/* if tree is not empty, then traverse */
		infix(treePtr->left);
		printf("%3d", treePtr->data);
		infix(treePtr->right);
	}
}

/* begin prefix order traversal of tree */
void prefix(treeNodePtr treePtr) {
	if(treePtr != NULL) {	/* if tree is not empty, then traverse */
		printf("%3d", treePtr->data);
		prefix(treePtr->left);
		prefix(treePtr->right);
	}
}

/* begin postfix order traversal of tree */
void postfix(treeNodePtr treePtr) {
	if(treePtr != NULL) {	/* if tree is not empty, then traverse */
		postfix(treePtr->left);
		postfix(treePtr->right);
		printf("%3d", treePtr->data);
	}
}

