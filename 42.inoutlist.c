#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node *next;
}*v[10];
int in[10],out[10];

void add(struct Node* ptr,int i){
	while (ptr->next!=NULL) ptr=ptr->next;
	ptr->next= (struct Node*)malloc(sizeof(struct Node));
	ptr->next->val=i;
	ptr->next->next=NULL;
}

void cal(struct Node* ptr){
	int i;
	i=ptr->val;
	ptr=ptr->next;
	while (ptr!=NULL){
	out[i]++;
	in[ptr->val]++;
	ptr=ptr->next;
	}

}

int main(){
	int i,n,x,y;

	for(i=0;i<10;i++) {
		v[i]=(struct Node*)malloc(sizeof(struct Node));
		v[i]->val=i;
		v[i]->next=NULL;
	}
	for(i=0;i<10;i++) in[i]=out[i]=0;
	printf("enter the number of vertexes(max 10):");
	scanf("%d",&n);
	printf("enter the number of conections:");
	scanf("%d",&i);
	printf("enter the conections:\n");
	while(i>0){
		i--;
		scanf("%d %d",&x,&y);
		add(v[x],y);
	}

	for(i=0;i<n;i++) cal(v[i]);

	printf("Indegree ");
	for(i=0;i<n;i++) printf("%d:%d ",i,in[i]);
	printf("\nOutdegree ");
	for(i=0;i<n;i++) printf("%d:%d ",i,out[i]);
	printf("\n");

	return 0;
}
