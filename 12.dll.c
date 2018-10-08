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
	head->left=NULL;
	head->right=NULL;
	
	do{
		scanf("%c",&x);
		switch(x){
			case 's':
				scanf("%d",&i);
				ptr=head->right;
				while (ptr!=NULL){ if (ptr->val==i) printf("found\n"); ptr=ptr->right;}
				break;
			case 'i':
				scanf("%d",&i);
				ptr=head;
				while (ptr->right!=NULL) ptr=ptr->right;
				ptr->right= (struct Node*)malloc(sizeof(struct Node));
				ptr->right->val=i;
				ptr->right->left=ptr;
				ptr->right->right=NULL;
				break;
			case 'd':
				ptr=head;
				while (ptr->right->right!=NULL) ptr=ptr->right;
				free(ptr->right);
				ptr->right=NULL;
				break;
			case 'p':
			
				ptr=head->right;
				while(ptr!=NULL){
					printf("%d ",ptr->val);
					ptr=ptr->right;
				}
				printf("\n");
				break;
		};
	}while(x!='e');

	return 0;
}
