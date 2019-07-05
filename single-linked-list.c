#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *createList(Node *);
void displayList(Node *);
int listSize(Node *);
void insertEnd(Node *, int);
Node *insertFront(Node **, int);
Node *insertAt(Node **, int, int);
Node *removeEnd(Node *);
Node *removeFront(Node **);
Node *removeAt(Node **, int);
int searchFirstOccurrence(Node *, int);
Node *deleteList(Node *);

int main(int argc, char **argv) {
	Node *head = NULL;
	int option, data, pos;

	do {
		printf("\n***********************************");
		printf("\n\tSINGLE-LINKED LIST");
		printf("\n***********************************");
		printf("\n");
		printf("\n 1. Create a list");
		printf("\n 2. Display list");
		printf("\n 3. Count list size");
		printf("\n 4. Add a new last node");
		printf("\n 5. Add a new first node");
		printf("\n 6. Add a node at a custom position");
		printf("\n 7. Remove last node");
		printf("\n 8. Remove first node");
		printf("\n 9. Remove a node at a custom position");
		printf("\n10. Search first occurrence of data");
		printf("\n11. Delete list");

		printf("\n\nEnter an option (-1 to exit) >> ");
		scanf("%d", &option);

		switch(option) {
			case 1:
				head = createList(head);
				printf("\n***** SINGLE LINKED LIST CREATED *****\n");
				break;

			case 2:
				displayList(head);
				break;

			case 3:
				printf("List size: %d\n", listSize(head));
				break;

			case 4:
				if(head == NULL) printf("\nCreate a list first!\n");
				else {
					printf("\nEnter data >> ");
					scanf("%d", &data);
					insertEnd(head, data);
				}
				break;

			case 5:
				if(head == NULL) printf("\nCreate a list first!\n");
				else {
					printf("\nEnter data >> ");
					scanf("%d", &data);
					head = insertFront(&head, data);
				}
				break;

			case 6:
				if(head == NULL) printf("\nCreate a list first!\n");
				else {
					printf("\nEnter data >> ");
					scanf("%d", &data);

					do {
						printf("\nEnter desired position to insert (1 - %d) >> ", (listSize(head) + 1)) ;
						scanf("%d", &pos);

						if(pos < 1 || pos > (listSize(head) + 1)) printf("Invalid position input. Try again.\n");
					} while(pos < 1 || pos > (listSize(head) + 1));
					head = insertAt(&head, data, pos);
				}
				break;

			case 7:
				if(head == NULL) printf("\nNothing to delete.\n");
				else head = removeEnd(head);
				break;

			case 8:
				if(head == NULL) printf("\nNothing to delete.\n");
				else head = removeFront(&head);
				break;

			case 9:
				do {
					printf("\nEnter desired position to delete (1 - %d) >> ", listSize(head)) ;
					scanf("%d", &pos);

					if(pos < 1 || pos > listSize(head)) printf("Invalid position input. Try again.\n");
				} while(pos < 1 || pos > listSize(head));
				head = removeAt(&head, pos);
				break;

			case 10:
				if(head == NULL) printf("\nCreate a list first!\n");
				else {
					printf("\nEnter data to be searched >> ");
					scanf("%d", &data);
					if(searchFirstOccurrence(head, data) < 0) printf("Sorry, this data is not found in this list.\n");
					else printf("First occurrence of input data in list: %d\n", searchFirstOccurrence(head, data));
				}
				break;

			case 11:
				if(head != NULL) {
					head = deleteList(head);
					printf("\n***** SINGLE LINKED LIST DELETED *****\n");
				} else printf("\nList already empty.\n");
				break;

			default:
				if(option != -1) printf("\nInvalid option entered. Try again.\n");
		}
	} while(option != -1);

	printf("\nGOODBYE\n\n");

	return 0;
}

Node *createList(Node *head) {
	/* Node *new_node, *ptr; */
	int num;
	char cont[2];

	do {
		printf("\nDo you wish to continue? (Y/N) >> ");
		scanf("%s", cont);
		getchar();
	} while(strcmp(cont, "Y") != 0 && strcmp(cont, "y") != 0 && strcmp(cont, "N") != 0 && strcmp(cont, "n") != 0);

	while(strcmp(cont, "N") != 0 && strcmp(cont, "n") != 0) {
		printf("\nEnter data >> ");
		scanf("%d", &num);

		/*
		new_node = (Node *)malloc(sizeof(Node));
		new_node->data = num;
		if(head == NULL) {
			new_node->next = NULL;
			head = new_node;
		} else {
			ptr = head;
			while(ptr->next != NULL) ptr = ptr->next;
			ptr->next = new_node;
			new_node->next = NULL;
		}
		*/

		if(head == NULL) head = insertFront(&head, num);
		else insertEnd(head, num);

		printf("\nList now: ");
		displayList(head);
		printf("\n");

		do {
			printf("Do you wish to continue? (Y/N) >> ");
			scanf("%s", cont);
			getchar();
		} while(strcmp(cont, "Y") != 0 && strcmp(cont, "y") != 0 && strcmp(cont, "N") != 0 && strcmp(cont, "n") != 0);
	}

	return head;
}

void displayList(Node *cur) {
	printf("\n");
	if(cur == NULL) printf("List is empty.");
	else {
		while(cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n");
}

int listSize(Node *cur) {
	int size;

	if(cur == NULL) return 0;

	for(size = 0; cur != NULL; cur = cur->next) size++;

	return size;
}

void insertEnd(Node *cur, int n) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = n;
	new_node->next = NULL;

	while(cur->next != NULL) cur = cur->next;
	cur->next = new_node;
}

Node *insertFront(Node **tmpHead, int n) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = n;
	if(*tmpHead == NULL) new_node->next = NULL;
	else new_node->next = *tmpHead;

	return new_node;
}

Node *insertAt(Node **tmpHead, int n, int pos) {
	int cur_pos;
	Node *cur = *tmpHead;

	if(pos == 1) return insertFront(tmpHead, n);
	else if(pos == (listSize(*tmpHead) + 1)) insertEnd(*tmpHead, n);
	else if(pos < 1 || pos > (listSize(*tmpHead) + 1)) printf("\nUnable to insert node at invalid position.\n");
	else {
		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->data = n;

		for(cur_pos = 1; cur_pos < (pos - 1); ) {
			cur_pos++;
			*tmpHead = (*tmpHead)->next;
		}
		new_node->next = (*tmpHead)->next;
		(*tmpHead)->next = new_node;
		*tmpHead = cur;
	}

	return *tmpHead;
}

Node *removeEnd(Node *head) {
	Node *cur = head;

	if(listSize(head) <= 1) return deleteList(head);
	while(cur->next->next != NULL) cur = cur->next;
	free(cur->next);
	cur->next = NULL;

	return head;
}

Node *removeFront(Node **tmpHead) {
	Node *oldHead = *tmpHead;

	if(oldHead->next == NULL) return deleteList(*tmpHead);

	*tmpHead = oldHead->next;
	free(oldHead);

	return *tmpHead;
}

Node *removeAt(Node **tmpHead, int pos) {
	int cur_pos;
	Node *oldNode, *cur = *tmpHead;

	if(pos == 1) return removeFront(tmpHead);
	else if(pos < 1 || pos > listSize(*tmpHead)) printf("\nUnable to delete node at invalid position.\n");
	else {
		for(cur_pos = 1; cur_pos < (pos - 1); ) {
			cur_pos++;
			*tmpHead = (*tmpHead)->next;
		}
		oldNode = (*tmpHead)->next;
		(*tmpHead)->next = oldNode->next;
		free(oldNode);
		*tmpHead = cur;
	}

	return *tmpHead;
}

int searchFirstOccurrence(Node *cur, int val) {
	int pos;
	for(pos = 0; cur != NULL; cur = cur->next) {
		pos++;
		if(cur->data == val) return pos;
	}
	return -1;
}

Node *deleteList(Node *head) {
	Node *tmp = head;

	if(head == NULL) printf("List already empty.\n");
	else {
		while(listSize(head) > 1) {
			head = removeFront(&tmp);
			tmp = head;
		}
		head = NULL;
	}

	return head;
}
