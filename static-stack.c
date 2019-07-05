#include <stdio.h>

#define MAX 5	/* size of stack */

int stack[MAX], top = -1;

void push(int stack[], int data);
int pop(int stack[]);
void displayStack(int stack[]);
int peek(int stack[]);

int main(int argc, char **argv) {
	int option, data;
	do {
		printf("\n***********************************");
		printf("\n\tSTATIC STACK");
		printf("\n***********************************");
		printf("\n");
		printf("\n1. Push");
		printf("\n2. Pull");
		printf("\n3. Peek");
		printf("\n4. Display");

		printf("\n\nEnter an option (-1 to exit) >> ");
		scanf("%d", &option);

		switch(option) {
			case 1:
				printf("Enter data >> ");
				scanf("%d", &data);
				push(stack, data);
				break;

			case 2:
				data = pop(stack);
				if(top >= -1) printf("Data on top of stack: %d\n", data);
				break;

			case 3:
				data = peek(stack);
				if(top > -1) printf("Data on top of stack: %d\n", data);
				break;

			case 4:
				displayStack(stack);
				break;

			default:
				if(option != -1) printf("\nInvalid option entered. Try again.\n");
		}
	} while(option != -1);

	printf("\nGOODBYE\n\n");

	return 0;
}

void push(int stack[], int data) {
	if(top > MAX - 1) printf("Stack is full! Push aborted\n");
	else {
		top++;
		stack[top] = data;
	}
}

int pop(int stack[]) {
	int data = -1;

	if(top < 0) printf("Stack is empty! Pop aborted\n");
	else {
		data = stack[top];
		top--;
	}

	return data;
}

void displayStack(int stack[]) {
	int i;
	if(top < 0) printf("Stack is empty!\n");
	else {
		for(i = top; i >= 0; i--) printf("%d ", stack[i]);
		printf("TOP\n");
	}
}

int peek(int stack[]) {
	if(top < 0) {
		printf("Stack is empty!\n");
		return -1;
	} else return (stack[top]);
}
