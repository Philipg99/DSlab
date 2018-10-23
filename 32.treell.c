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

void heapify(int a[],int n,int i){
    int large=i,l=2*i+1,r=2*i+2,t=0;

    if (l<=n && a[large]<a[l]) large=l;
    if (r<=n && a[large]<a[r]) large=r;

    if (large!=i){
        t=a[i];
        a[i]=a[large];
        a[large]=t;
        if (large<=n/2) heapify(a,n,large);
    }
}

void heap(int a[],int n){
    int t=0,i;
    for (i=n/2;i>=0;i--) heapify(a,n,i);
}

void print(struct Node* ptr){
	printf(" ");
	if (ptr->left!=NULL) print(ptr->left);
	printf("%c",ptr->val);
	if (ptr->right!=NULL) print(ptr->right);
	printf(" ");
	
}

int main(){
	int i , a[100];
	prinft("enter the number of intial elements")
	root=NULL;
	cur=root;
	print(root);
	printf("\n");
	do{
		scanf("%c",&x);
		switch(x){
			case 's':
				scanf("%d",&i);
				break;
			case 'i':
				scanf("%d",&i);

				break;
			case 'd':

				break;
			case 'p':
			
				printf("\n");
				break;
		};
	}while(x!='e');



	return 0;

}
