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
	
	do{
		scanf("%c",&x);
		switch(x){
			case 's':
				scanf("%d",&i);
				ptr=head->right;
				while (ptr!=head){ if (ptr->val==i) printf("found\n"); ptr=ptr->right;}
				break;
			case 'i':
				scanf("%d",&i);
				ptr=head->right;
				while (ptr->right!=head) ptr=ptr->right;
				ptr->right= (struct Node*)malloc(sizeof(struct Node));
				ptr->right->val=i;
				ptr->right->right=head;
				ptr->right->left=ptr;
				head->left=ptr->right;
				break;
			case 'd':
				ptr=head;
				while (ptr->right->right!=head) ptr=ptr->right;
				free(ptr->right);
				ptr->right=head;
				head->left=ptr;
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
