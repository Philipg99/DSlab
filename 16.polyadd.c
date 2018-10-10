#include<stdio.h>
#include <stdlib.h>

struct Node{
	int co;
	int ex;
	struct Node *next;
};

int main(){
	int c,e;
	struct Node *head1,*head2,*ptr,*ptr2,*pre;
	head1=(struct Node*)malloc(sizeof(struct Node));
	head1->next=NULL;
	head2=(struct Node*)malloc(sizeof(struct Node));
	head2->next=NULL;

	ptr=head1;
	do{
		scanf("%d %d",&c,&e);
		ptr->next= (struct Node*)malloc(sizeof(struct Node));
		ptr->next->co=c;
		ptr->next->ex=e;
		ptr=ptr->next;
		ptr->next=NULL;

	}while(e>0);

	ptr=head2;
	do{
		scanf("%d %d",&c,&e);
		ptr->next= (struct Node*)malloc(sizeof(struct Node));
		ptr->next->co=c;
		ptr->next->ex=e;
		ptr=ptr->next;
		ptr->next=NULL;

	}while(e>0);


	ptr=head1->next;
	ptr2=head2->next;
	pre=head1;
	while (ptr2!=NULL){
		if (ptr->ex>ptr2->ex && ptr!=NULL) {pre=ptr; ptr=ptr->next;}
		if (ptr->ex==ptr2->ex) {ptr->co+=ptr2->co; ptr2=ptr2->next;}
		else if (ptr->ex<ptr2->ex) {
		pre->next=ptr2;
		ptr2=ptr2->next;
		pre->next->next=ptr;
		}
	}

	ptr=head1->next;
	while(ptr!=NULL){
		printf("%dx^%d ",ptr->co,ptr->ex);
		ptr=ptr->next;
	}
	printf("\n");


	return 0;
}
