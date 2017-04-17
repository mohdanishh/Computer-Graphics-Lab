#include <stdio.h>
#define SIZE 10

typedef struct LinkedList{
	int data;
	int index;
	struct LinkedList *add;
}NODE;

void create(NODE **header, int val, int index){
	NODE *current;
	if(*header==NULL){
		*header=(NODE *)malloc(sizeof(NODE));
		(*header)->data=val;
		(*header)->index=index;
		(*header)->add=NULL;
	}else{
		current=*header;
		while(current->add!=NULL){
			current=current->add;
		}
		current->add=(NODE *)malloc(sizeof(NODE));
		current->add->data=val;
		current->add->index=index;
		current->add->add=NULL;
	}
}

void split(NODE **header){
	NODE *temp;
	if(*header==NULL){
		printf("Linked List is Empty.\n");
	}else{
		temp=*header;
		int arO[SIZE/2];
		int arE[SIZE/2];
		int Ocount=0;
		int Ecount=0;
		while(temp!=NULL){
			if((temp->index)%2==1){
				arO[Ocount]=temp->data;
				Ocount++;
			}else{
				arE[Ecount]=temp->data;
				Ecount++;
			}
			temp=temp->add;
		}
		int i;
		printf("ODD: ");
		for(i=0; i<SIZE/2;i++){
			printf("%d\t",arO[i]);
		}
		printf("\nEVEN: ");
		for(i=0; i<SIZE/2;i++){
			printf("%d\t",arE[i]);
		}
	}
}

void main(){
	NODE *head= NULL;
	printf("Insert %d values: \n",SIZE);
	int i;
	int val;
	for(i=1; i<=SIZE; i++){
	scanf("%d",&val);
		create(&head, val, i);
	}
	split(&head);
	return;
}
