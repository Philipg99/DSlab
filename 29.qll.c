#include<stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *next;
};

int main(){
	char x;
	int i;
	struct Node *head,*ptr;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->next=NULL;
	printf("i:insert d:delete p:print e:exit\n");
	do{
		scanf("%c",&x);
		switch(x){
			getchar();
			case 'i':
				scanf("%d",&i);
				ptr=head;
				while (ptr->next!=NULL) ptr=ptr->next;
				ptr->next= (struct Node*)malloc(sizeof(struct Node));
				ptr->next->val=i;
				break;
			case 'd':
				if(head->next!=NULL){
				ptr=head->next->next;
				free(head->next);
				head->next=ptr;}
				else printf("empty queue");
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
