#include<stdio.h>
#include <stdlib.h>

struct Node{
	int co;
	int ex;
	struct Node *next;
};

int main(){
	int c,e;
	struct Node *head1,*head2,*head3,*ptr,*ptr2,*ptr3,*pre;
	head1=(struct Node*)malloc(sizeof(struct Node));
	head1->next=NULL;
	head2=(struct Node*)malloc(sizeof(struct Node));
	head2->next=NULL;
	head3=(struct Node*)malloc(sizeof(struct Node));
	head3->next=NULL;

	ptr=head1;
	do{
		scanf("%d %d",&c,&e);
		ptr->next= (struct Node*)malloc(sizeof(struct Node));
		ptr->next->co=c;
		ptr->next->ex=e;
		ptr=ptr->next;
		ptr->next=NULL;

	}while(e>0);
	
	ptr=head1->next;
	while(ptr!=NULL){
		printf("%dx^%d ",ptr->co,ptr->ex);
		ptr=ptr->next;
	}
	printf("\n");

	ptr=head2;
	do{
		scanf("%d %d",&c,&e);
		ptr->next= (struct Node*)malloc(sizeof(struct Node));
		ptr->next->co=c;
		ptr->next->ex=e;
		ptr=ptr->next;
		ptr->next=NULL;

	}while(e>0);

	ptr=head2->next;
	while(ptr!=NULL){
		printf("%dx^%d ",ptr->co,ptr->ex);
		ptr=ptr->next;
	}
	printf("\n");

	for(ptr=head1->next;ptr!=NULL;ptr=ptr->next){
		for(ptr2=head2->next;ptr2!=NULL;ptr2=ptr2->next){
			c=ptr->co*ptr2->co;
			e=ptr->ex+ptr2->ex;
			pre=head3;
			ptr3=head3->next;
			while(1==1){
				if (ptr3==NULL){
					pre->next=(struct Node*)malloc(sizeof(struct Node));
					pre=pre->next;
					pre->co=c;
					pre->ex=e;
					pre->next=NULL;
					break;
				}
				if(ptr3->ex<e){pre=ptr3;ptr3=ptr3->next;continue;}
				if(ptr3->ex==e){ptr3->co+=c;break;}
				if(ptr3->ex>e){
					pre->next=(struct Node*)malloc(sizeof(struct Node));
					pre=pre->next;
					pre->co=c;
					pre->ex=e;
					pre->next=ptr3;
					break;
				}
			}
		}
	}

	ptr=head3->next;
	while(ptr!=NULL){
		printf("%dx^%d ",ptr->co,ptr->ex);
		ptr=ptr->next;
	}
	printf("\n");


	return 0;
}
