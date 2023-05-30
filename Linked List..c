#include <stdio.h>
#include <stdlib.h>

struct student{
	int no;
	char name[15];
	int age;
	struct student *next;
};
typedef struct student node;
node *head, *newNode;

//Dugum Olusturma
node *createList(){
	int n,k; 
	node *head, *p;
	printf("How many students in the list:");
	scanf("%d",&n);
	for(k=0;k<n;k++){
		if(k=0){
			head = (node*) malloc(sizeof(node));
			p = head;
		}else{
			p->next = (node*) malloc(sizeof(node));
			p = p->next;
		}
		printf("Enter %d. student number:",k+1);         scanf("%d",&p->no);
		printf("Enter %d. student name:",k+1);           scanf("%s",p->name);
		printf("Enter %d. student age:",k+1);            scanf("%d",&p->age);
	}
	p->next = NULL;
	return head;
}
//Listede Dolasma
void transeList(node *head){
	int counter = 1;
	node *p;
	p = head;
	while (p!=NULL){
		printf("%d- %d %s %d\n",counter, p->no, p->name, p->age);
		p = p->next;
		counter++;		
	}
}

//Listeye Dugum Ekleme
node *addNode(node *head){
	int stdNo;
	node *p, *q;
	node *newNode = (node*) malloc(sizeof(node));
	printf("Enter new student number:");      scanf("%d",&newNode->no);
	printf("Enter new student name:");        scanf("%s",newNode->name);
	printf("Enter new student age:");         scanf("%d",&newNode->age);
	
	printf("Enter student number that new record will be added before:\n");
	printf("Press 0 to add to the end of list\n");
	scanf("%d",&stdNo);
	p = head;
	if(p->no == stdNo){
		newNode->next = p;
		head = newNode;
	}else{
		while(p->next != NULL && p->no != stdNo){
			q = p;
			p = p->next;
		}
		if(p->no == stdNo){
			q->next = newNode;
			newNode->next = p;
		}else if(p->next == NULL){
			p->next == newNode;
			newNode->next = NULL;
		}
	}
	return head;	
}

node *deleteNode(node *head){
	int stdNo;
	node *p, *q;
	
	printf("Enter student number that will be deleted:");
	scanf("%d",&stdNo);
	
	p = head;
	if(p->no = stdNo){
		head = p->next;
		free(p);
	}else{
		while(p->next != NULL && p->no != stdNo){
			q = p;
			p = p->next;
			free(p);
		}
		if(p->no == stdNo){
			q->next = p->next;
			free(p);
		}
		else if(p->next == NULL){
			printf("No node found to delete!");
		}
	}
	return head;
}

int main(){
	node *head;
	int selection = 0;
	printf("1-Create  List 2-Traverse List  3-Add Node  4-Delete Node  5-Exit");
	while(1){
		printf("Selection [1-5]");   scanf("%d",&selection);
		switch(selection){
			case 1: 
				head = createList();
				printf("Adres:%x\n",head);
				break;
			case 2:
				transeList(head);
				break;
			case 3:
				head = addNode(head);
				break;
			case 4:
				head = deleteNode(head);
				break;
			case 5:
				exit(0);
		}
	}
}



