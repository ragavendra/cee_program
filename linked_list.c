#include <stdio.h>
#include <stdlib.h>

int main() {

	int index;
	typedef struct node {
		int value;
		struct node *next;
	}node_t;

	node_t *linked_list;
	node_t *current;
	linked_list = malloc(sizeof(node_t));
	current = linked_list;

	//linked_list = malloc(sizeof(node_t));
	//linked_list->value = 1;
	//linked_list->next = malloc(sizeof(node_t));
	//linked_list->next->value = 2;

	for (index = 0; index < 10; index++) {
		//current
		linked_list->value = index;
		linked_list->next = malloc(sizeof(node_t));
		linked_list = linked_list->next;
		//printf("Hi");
	}

	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
		//printf("Hello");
	}

	return 0;
}
