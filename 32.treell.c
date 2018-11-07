#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



struct Node{
	int val;
	struct Node *left;
	struct Node *right;
}*root,*par,*ptr,*tmp;

struct Node* new(int v){
	struct Node* ptr;
	ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->val=v;
	return ptr;
}

void print(struct Node* ptr){
	printf("(");
	if (ptr->left!=NULL) print(ptr->left);
	printf(" %d ",ptr->val);
	if (ptr->right!=NULL) print(ptr->right);
	printf(")");
}

struct Node* scan(struct Node* ptr,int i){
	if (ptr!=NULL){
		if (ptr->val==i) return ptr;
		if (ptr->val<i) scan(ptr->right,i);
		else if (ptr->val>=i) scan(ptr->left,i);}
	else return NULL;
}



void insert(struct Node* ptr,int i){

	if(ptr->val<i) if (ptr->right!=NULL) insert(ptr->right,i);
		else ptr->right=new(i);
	else if (ptr->left!=NULL) insert(ptr->left,i);
		else ptr->left=new(i);
 	
}


void delete(struct Node* ptr,int i){
	if (scan(ptr,i)){
	par=ptr;
	while (ptr->val!=i){
		if (ptr->val<i) {par=ptr;ptr=ptr->right;}
		else if (ptr->val>=i) {ptr=ptr->left;}
	}
	}
	if (ptr->right!=NULL){
		tmp=ptr->right;
		par=ptr;
		if (tmp->left==NULL){
			ptr->val=tmp->val;
			ptr->right=tmp->right;
			free(tmp);
		}
		else{
			while(tmp->left!=NULL){ par=tmp;tmp=tmp->left;}
			ptr->val=tmp->val;
			par->left=tmp->right;
			free(tmp);
		}
		return;

	}
	else if(ptr->left!=NULL){
		tmp=ptr->left;
		par=ptr;
		if (tmp->right==NULL){
			ptr->val=tmp->val;
			ptr->left=tmp->left;
			free(tmp);
		}
		else{
			while(tmp->right!=NULL){ par=tmp;tmp=tmp->right;}
			ptr->val=tmp->val;
			par->right=tmp->left;
			free(tmp);
		}
		return;
	}
	if (ptr==root){
		free(ptr);
		root=NULL;
	
	}
	else{	
		if (par->right==ptr) {par->right=NULL; free(ptr);}
		else if (par->left==ptr) {par->left=NULL; free(ptr);}	
	}

}
	
int main(){
	int i ;
	char x;
	root=NULL;
	printf("\n");
	do{
		scanf("%c",&x);
		switch(x){
			getchar();
			printf("i:insert s:scan d:delete p:print e:exit :");
			case 's':
				scanf("%d",&i);
				if (scan(root,i)) printf("found");
				break;
			case 'i':
				scanf("%d",&i);
				if (root==NULL) root=new(i);
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
