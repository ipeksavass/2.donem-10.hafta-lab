#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int number;
	struct node* next;
}Node;

void add_node(Node** head_ptr, int number){
	Node* new_node = malloc(sizeof(Node));
	new_node->number = number;
	new_node->next = NULL;
	
	if(*head_ptr == NULL){
		*head_ptr = new_node;
		return;
	}
	
	if(number % 2 == 1){
		new_node->next = *head_ptr;
		*head_ptr = new_node;

	}
	else{
		Node* current = *head_ptr;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = new_node;
	}
	
}

void print_list(Node* headd){
	Node* current = headd;
	printf("List Values:");
	while(current != NULL){
		printf("%d ",current->number);
		current = current->next;
	}
	printf("\n");
}

Node* cut_last_add_head(Node* headd){
	if(headd == NULL  || headd->next == NULL)
		return;
	
	Node* previous = NULL;
	Node* current = headd;
	
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	//current is the last  in the list
	previous->next = NULL;
	current->next = headd;
	headd = current;
	return headd;
}

void delete_middle_node(Node** head_ptr){
	if(*head_ptr == NULL || (*head_ptr)->next == NULL)
		return;
	
	Node* slow = *head_ptr;   //it progresses one by one
	Node* fast = *head_ptr;   //it progresses two by two
	Node* previous = NULL;
	
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		previous = slow;
		slow = slow->next;
	}
	previous->next = slow->next;
	free(slow);
}

void swap_first_last(Node** head_ptr){
	if(*head_ptr == NULL || (*head_ptr)->next == NULL)
		return;
	Node* current = *head_ptr;
	Node* previous = NULL;
	
	//current son elemana ulasacak, previous sondan bir oncekine ulasir
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	current->next = (*head_ptr)->next;
	(*head_ptr)->next = NULL;
	previous->next = *head_ptr;
	*head_ptr = current;	
}

Node* cut_first_add_last(Node* headd){
	if(headd == NULL || headd->next == NULL)
		return;
	Node* current = headd;
	
	while(current->next != NULL){
		current = current->next;
	}
	current->next = headd;
	headd = headd->next;
	current->next->next = NULL;
	
	return headd;
}

int main(){
	int num;
	char choise;
	Node* head = NULL;
	while(1){
		printf("*****************\n");
		printf("1-Add Node\n"
			   "2-List Nodes\n"
			   "3-Cut Last and Add to Head\n"
			   "4-Delete Middle Node\n"
			   "5-Swap Last and Head\n"
			   "6-Cut First and Add to Last\n");
		choise = getch();	
		switch(choise){
			case'1':
				printf("Enter a number:");   scanf("%d",&num);
				add_node(&head,num);
				print_list(head);
				break;
			case'2':
				print_list(head);
				break;
			case'3':
				head = cut_last_add_head(head);
				print_list(head);
				break;	
			case'4':
				delete_middle_node(&head);
				print_list(head);
				break;	
			case'5':
				swap_first_last(&head);
				print_list(head);
				break;
			case'6':
				head = cut_first_add_last(head);
				print_list(head);
				break;
		}
	}
}
