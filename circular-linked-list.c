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
Node *removeEnd(Node *);
Node *removeFront(Node **);
Node *deleteList(Node *);

int main(int argc, char **argv) {Node *head = NULL;
	int option, data;

	do {
		printf("\n***********************************");
		printf("\n\tCIRCULAR-LINKED LIST");
		printf("\n***********************************");
		printf("\n");
		printf("\n1. Create a list");
		printf("\n2. Display list");
		printf("\n3. Count list size");
		printf("\n4. Add a new last node");
		printf("\n5. Add a new first node");
		printf("\n6. Remove last node");
		printf("\n7. Remove first node");
		printf("\n8. Delete list");

		printf("\n\nEnter an option (-1 to exit) >> ");
		scanf("%d", &option);

		switch(option) {
			case 1:
				head = createList(head);
				printf("\n***** CIRCULAR LINKED LIST CREATED *****\n");
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
				if(head == NULL) printf("\nNothing to delete.\n");
				else head = removeEnd(head);
				break;

			case 7:
				if(head == NULL) printf("\nNothing to delete.\n");
				else head = removeFront(&head);
				break;

			case 8:
				if(head != NULL) {
					head = deleteList(head);
					printf("\n***** CIRCULAR LINKED LIST DELETED *****\n");
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

void displayList(Node *head) {
	Node *cur;
	
	printf("\n");
	cur = head;
	if(cur == NULL) printf("List is empty.");
	else {
		do {
			printf("%d ", cur->data);
			cur = cur->next;
		} while(cur != head);
	}
	printf("\n");
}

int listSize(Node *head) {
	int size = 0;
	Node *cur = head;

	if(cur == NULL) return 0;

	do {
		size++;
		cur = cur->next;
	} while(cur != head);

	return size;
}

void insertEnd(Node *head, int n) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *cur = head;

	new_node->data = n;
	new_node->next = head;

	while(cur->next != head) cur = cur->next;
	cur->next = new_node;
}

Node *insertFront(Node **tmpHead, int n) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *cur;

	new_node->data = n;
	if(*tmpHead == NULL) new_node->next = new_node;
	else {
		cur = *tmpHead;
		while(cur->next != *tmpHead) cur = cur->next;
		cur->next = new_node;
		new_node->next = *tmpHead;
	}

	return new_node;
}

Node *removeEnd(Node *head) {
	Node *cur = head;

	if(listSize(head) <= 1) return deleteList(head);
	while(cur->next->next != head) cur = cur->next;
	free(cur->next);
	cur->next = head;

	return head;
}

Node *removeFront(Node **tmpHead) {
	Node *cur = *tmpHead;

	if((*tmpHead)->next == *tmpHead) return deleteList(*tmpHead);
	do {
		cur = cur->next;
	} while(cur->next != *tmpHead);

	*tmpHead = (*tmpHead)->next;
	free(cur->next);
	cur->next = *tmpHead;

	return *tmpHead;
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
