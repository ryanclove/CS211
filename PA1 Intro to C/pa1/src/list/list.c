#include <stdio.h>
#include <stdlib.h>

struct node {
	int number; 
	struct node *next; 
}; 

int findLength( struct node *head) {
	int length = 0; 
	while( head != NULL ) {
		length++; 
		head = head->next; 
	}
	return length; 
}

void print( struct node *head ) {
	int length = findLength(head); 
	printf("%d :", length); 
	
	while( head != NULL ) {
		printf(" %d", head->number);  
		head = head->next; 
	} 	
	printf("\n"); 
}

int existingNode( struct node *head, int value) { 
	while( head != NULL ) {
		if( head->number == value ) {
			return 0; 
		}
		head = head->next; 
	}
	return 1; 
}


int nodeIndex( struct node *head, int value) {	
	int length = findLength(head); 
	int i = 0; 
	while( head != NULL ) {
		if( value > head->number ) {
			i++; 
		}	
		head = head->next; 
	}
	

	if( i >= length ) {
		i = -1;  
		return i; 
	}
	return i; 
}

void insert( struct node **head, int value ) {
	// create node
	struct node *new = NULL;
	new = (struct node*)malloc(sizeof(struct node)); 
	new->number = value; 
	new->next = NULL; 
	
	// empty head 
	if( *head == NULL ) { 
		*head = new; 
		return; 
	}
	
	// duplicate
	int duplicate = existingNode(*head, value); 
	if( duplicate == 0 ){ 
		return; 		
	}
	// insert front
	if( new->number < (*(&(*head)))->number ) {
		new->next = *head; 
		*head = new;
		return;  		
	}	

	// insert at end
	int insertIndex = nodeIndex(*head, value);
	if( insertIndex == -1 ) {	
		struct node *last = NULL;
		last = *head; 
		while( last->next != NULL ) {
			last = last->next; 
		}	
		last->next = new; 
		return; 
	} 
	
	struct node *copy = *head; 
	while( copy && copy->next ) {
		if( copy->next->number > value ) {
			new->next = copy->next; 
			copy->next = new;
			return; 
		}
		copy = copy->next; 
	}
		 
} 

void delete(struct node **head, int value) { 
	struct node *copy = NULL; 
	if( *head == NULL ) { 
		return; 
	}
	
	int duplicate = existingNode(*head, value);
	if( duplicate == 0 ) {
		if( value == (*(&(*head)))->number ) {
			*head = (*(&(*head)))->next;  
			return; 
		}
		copy = *head; 
		while( copy != NULL ) {
			if( copy->next->number == value ) {
				copy->next = copy->next->next; 
				return; 
			}
			copy = copy->next; 
		}		
	}
	else
	{
		return; 
	}
	
}

int main(int argc, char *argv[])
{
	struct node *head = NULL;
	char c; 
	int n;  
	
	while(1) {
		if( scanf(" %c %d", &c, &n) == 2 ) {
			if( c == 'i' ) {
				insert(&head, n);
				print(head);
			}
			if( c == 'd' ) {
				delete(&head, n);
				print(head);
			}
		}
		else
		{
			return EXIT_SUCCESS; 
		}
	}
}
