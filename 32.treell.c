#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



struct Node{
	int val;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
}*root,*cur;

struct Node* new(int v,struct Node* i){
	struct Node* ptr;
	ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->parent=i;
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->val=v;
	return ptr;
}

void print(struct Node* ptr){
	
	if (ptr->left!=NULL) print(ptr->left);
	printf(" %d ",ptr->val);
	if (ptr->right!=NULL) print(ptr->right);
	
}

void scan(struct Node* ptr,int i){
	
	if (ptr->val==i) {printf("found"); return;}
	if (ptr->val<i) scan(ptr->right,i);
	else if (ptr->val>=i) scan(ptr->left,i);
	
}



void insert(struct Node* ptr,int i){

	if(ptr->val<i) if (ptr->right!=NULL) insert(ptr->right,i);
		else ptr->right=new(i,ptr);
	else if (ptr->left!=NULL) insert(ptr->left,i);
		else ptr->left=new(i,ptr);
 	
}

struct Node* find(struct Node* ptr,int i){
	
	if (ptr->val==i) return ptr;
	if (ptr->val<i) scan(ptr->right,i);
	else if (ptr->val>=i) scan(ptr->left,i);
	
}

void delete(struct Node* ptr,int i){
	ptr=find(ptr,i);
	cur=ptr;
	while(ptr->right!=NULL) ptr=ptr->right;
	cur->val=ptr->val;	
	if (ptr->left!=NULL) ptr->parent->right=ptr->left; 
	free(ptr);
}
int main(){
	int i ;
	char x;
	root=NULL;
	cur=root;
	printf("\n");
	do{
		scanf("%c",&x);
		switch(x){
			case 's':
				scanf("%d",&i);
				scan(root,i);
				break;
			case 'i':
				scanf("%d",&i);
				if (root==NULL) root=new(i,NULL);
				else insert(root,i);
				break;
			case 'd':
				scanf("%d",&i);
				delete(root,i);
				break;
			case 'p':
				print(root);
				printf("\n");
				break;
		};
	}while(x!='e');
	return 0;

}
