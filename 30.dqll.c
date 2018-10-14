#include<stdio.h>
#include <stdlib.h>

void dqf()

void dqb()

void eqf()

void eqb()

struct Node{
	int val;
	struct Node *next;
}

int main(){
	char x;
	int i;
	struct Node *head,*ptr;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->next=NULL;
	
	do{
		scanf("%c",&x);
		switch(x){

			case 'i':
				scanf("%d",&i);
				ptr=head;
				while (ptr->next!=NULL) ptr=ptr->next;
				ptr->next= (struct Node*)malloc(sizeof(struct Node));
				ptr->next->val=i;
				break;
			case 'd':
				ptr=head;
				while (ptr->next->next!=NULL) ptr=ptr->next;
				free(ptr->next);
				ptr->next=NULL;
				break;
			case 'p':
			
				ptr=head->next;
				while(ptr!=NULL){
					printf("%d ",ptr->val);
					ptr=ptr->next;
				}
				printf("\n");
				break;
		};
	}while(x!='e');

	return 0;
}
