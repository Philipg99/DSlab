#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isexp(char a){
	if( a=='+' || a=='-' || a=='*' || a=='/' || a=='^') return true;
	return false;	
}

struct Node{
	char val;
	bool full;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
}*root,*cur;

struct Node* new(char v,struct Node* i){
	struct Node* ptr;
	ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->parent=i;
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->val=v;
	if (!isexp(v)) ptr->full=true; else ptr->full=false;
	return ptr;
}

void print(struct Node* ptr){
	printf("(");
	if (ptr->left!=NULL) print(ptr->left);
	printf("%c",ptr->val);
	if (ptr->right!=NULL) print(ptr->right);
	printf(")");
	
}

int main(){
	char exp[100];
	int i;
	printf("enter a prefix expertion: ");
	scanf("%s",exp);
	root=new(exp[0],NULL);
	cur=root;

	for(i=1;i<strlen(exp);i++){
		re:
		if (cur->left==NULL){
			cur->left=new(exp[i],cur);
			if (cur->left->full==false) cur=cur->left;
			continue;
		}
		if (cur->right==NULL){
			cur->right=new(exp[i],cur);
			if (cur->right->full==false) cur=cur->right;
			continue;
		}
		if (cur!=root && cur->right->full && cur->left->full){ 
				cur->full=true;
				cur=cur->parent;
				goto re;
			}
			
		
		
	}
	print(root);
	printf("\n");



	return 0;

}
