#include<stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *next;
}*head,*ptr;


void dqf(){
	if(head->next!=NULL){
		ptr=head->next->next;
		free(head->next);
		head->next=ptr;}
	else printf("empty queue");
}

void dqb(){
	ptr=head;
	while (ptr->next->next!=NULL) ptr=ptr->next;
	free(ptr->next);
	ptr->next=NULL;
}

void eqb(int i){
	ptr=head;
	while (ptr->next!=NULL) ptr=ptr->next;
	ptr->next= (struct Node*)malloc(sizeof(struct Node));
	ptr->next->val=i;
	ptr->next->next=NULL;
}

void eqf(int i){
	ptr=head->next;
	head->next= (struct Node*)malloc(sizeof(struct Node));
	head->next->val=i;
	head->next->next=ptr;
	
}

int main(){
	char x;
	int i;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->next=NULL;
	
	do{
		getchar();
		printf("1.enqueue front\n2.enqueue back\n3.dequeue front\n4.dequeue back\n5.print\n");
		scanf("%c",&x);
		switch(x){

			case '1':
				scanf("%d",&i);
				eqf(i);
				break;
			case '2':
				scanf("%d",&i);
				eqb(i);
				break;
			case '3':
				dqf();
				break;
			case '4':
				dqb();
				break;
			case '5':
			
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
