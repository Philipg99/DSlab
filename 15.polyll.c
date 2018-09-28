#include<stdio.h>
#include <stdlib.h>

struct Node{
	int co;
	int ex;
	struct Node *next;
}*head,*ptr;

int main(){
	int c,e;
	struct Node *head,*ptr;
	head->next=NULL;
	ptr=head;
	do{
		scanf("%d %d",&c,&e);
		ptr->next= (struct Node*)malloc(sizeof(struct Node));
		ptr->next->co=c;
		ptr->next->ex=e;
		ptr=ptr->next;
		ptr->next=NULL;

	}while(e>0);

	ptr=head->next;
	while(ptr!=NULL){
		printf("%dx^%d ",ptr->co,ptr->ex);
		ptr=ptr->next;
	}
	printf("\n");

	return 0;
}
