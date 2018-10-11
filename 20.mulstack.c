#include<stdio.h>

void pop(int *i,int *j,int d){
	if (d==1 && *i>0) (*i)--; else printf("empty stack\n");
	if (d==2 && *j<9) (*j)++;else printf("empty stack\n");
	}

void push(int a[],int x,int *i,int *j ,int d){
	if (d==1) if(*i<*j) a[(*i)++]=x;else printf("full stack\n");
	if (d==2) if(*j>*i) a[(*j)--]=x;else printf("full stack\n");
	}

void print(int a[],int i,int j,int d){
	int p;
	if (d==1) for (p=0;p<i;p++) printf("%d ",a[p]);
	if (d==2) for (p=9;p>j;p--) printf("%d ",a[p]);
	printf("\n");
}

int main(){
	int a[10],i=0,j=9,x,d,c;

	do{
	printf("chose array 1or 2\n");
	scanf("%d",&d);
	printf("1:pop\n2:push\n3:print\n4:exit\n");
	scanf("%d",&c);
	switch(c){
		case 1: pop(&i,&j,d); break;
		case 2: scanf("%d",&x); push(a,x,&i,&j,d); break;
		case 3: print(a,i,j,d); break;
		default: break;
	};
	}while(c!=4);
	return 0;
}
