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

//reverse the list
void reverse (node_t **head) {

	node_t *current = *head;
	node_t *previous = NULL;
	node_t *next = NULL;
	
	while (current != NULL) {

		//copy pointer next to a new node
		//before overwriting it
		next = current->next;

		//reverse the next pointer
		current->next = previous;

		//step forward
		previous = current;
		current = next;
	}

	*head = previous;
}

//display list
void display_list (node_t *head) {

	int index = 0;

	//prints the linked list
	while (head != NULL) {
		printf("%d ", head->value);
		head = head->next;
		//printf("Hello");
		index++;
		if (index > 20)
			break;
	}

}

int main() {
	
	//allocate memory for the structure
	node_t *linked_list = NULL;

	//copy variableas we will traverse linked_list
	//and its address will change obviously
	node_t *current = NULL;

	linked_list = malloc(sizeof(node_t));
	linked_list->value = 0;
	current = linked_list;
	
	for (int index = 1; index < 10; ++index) {
		linked_list->next = malloc(sizeof(node_t));
		linked_list->next->value = index;
		//printf("Hi %d", linked_list->value);
		linked_list = linked_list->next;
	}
		
	//display_list( current );
	
	//pass the whole structure head
	push_last ( current, 36); 

	//pass the address of the first structure
	push_head ( &current, 48);

	//lets reverse the list
	reverse ( &current );

	//display
	display_list( current );

	return 0;
}
