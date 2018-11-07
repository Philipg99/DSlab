#include<stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *next;
}*head,*ptr;

int main(){
	char x;
	int i;
	struct Node *head,*ptr;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->next=NULL;
	do{
		getchar();	
		printf("i:insert s:scan d:delete p:print e:exit :");
		scanf("%c",&x);
		switch(x){
			case 's':
				scanf("%d",&i);
				ptr=head->next;
				while (ptr!=NULL){ if (ptr->val==i) printf("found\n"); ptr=ptr->next;}
				break;
			case 'i':
				scanf("%d",&i);
				ptr=head;
				while (ptr->next!=NULL) ptr=ptr->next;
				ptr->next= (struct Node*)malloc(sizeof(struct Node));
				ptr->next->val=i;
				ptr->next->next=NULL;
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
