#include<stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *left;
	struct Node *right;
};

int main(){
	char x;
	int i;
	struct Node *head,*ptr;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->right=head;
	head->left=head;
	printf("i:insert d:delete p:print :");
	do{
		scanf("%c",&x);
		switch(x){
			getchar();
			
			case 'i':
				scanf("%d",&i);
				ptr=head->right;
				head->right= (struct Node*)malloc(sizeof(struct Node));
				head->right->val=i;
				ptr->left=head->right;
				head->right->left=head;
				head->right->right=ptr;
				break;
			case 'd':
				ptr=head->left->left;
				if (head->left!=head){
				free(head->left);
				ptr->right=head;
				head->left=ptr;}
				else printf("emptuy queue");
				break;
			case 'p':
				ptr=head->right;
				while(ptr!=head){
					printf("%d ",ptr->val);
					ptr=ptr->right;
				}
				printf("\n");
				break;
		};
	}while(x!='e');

	return 0;
}
