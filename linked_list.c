#include <stdio.h>
#include <stdlib.h>

//define a type node as a structure
//with an int value and a pointer of its own type
//called next
typedef struct node {
	int value;
	struct node *next;
}node_t;

//add element to the last of the list
void push_last (node_t *head ,int value) {

	node_t *current = head;
	
	while (current->next != NULL) {
		//printf("%d\n", current->value);
		current = current->next;
		//printf("Hello");
	}

	current->next = malloc(sizeof(node_t));
	current->next->value = value;
	//current->next->next = NULL;
}

//add element to the head
void push_head (node_t **head ,int value) {

	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;
	new_node->next = *head;
	*head = new_node;
}

int main() {
	
	//allocate memory for the structure
	node_t *linked_list = malloc(sizeof(node_t));

	//copy variableas we will traverse linked_list
	//and its address will change obviously
	node_t *current = linked_list ;

	for (int index = 0; index < 10; index++) {
		//current
		linked_list->value = index;
		linked_list->next = malloc(sizeof(node_t));
		//printf("Hi %d", linked_list->value);
		linked_list = linked_list->next;
	}

	//now points to the last structure
	//linked_list = NULL;

	//pass the whole structure head
	push_last ( current, 36); 

	//pass the address of the first structure
	push_head ( &current, 48);
	
	//prints the linked list
	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
		//printf("Hello");
	}

	return 0;
}
