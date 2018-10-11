#include<stdio.h>

void pop(int *i){
	if (*i>0) (*i)--;
	else printf("empty stack\n");		
}

void push(int a[],int x,int *i){
	if (*i<10) a[(*i)++]=x;
	else printf("full stack\n");
}

void print(int a[],int i){
	int j;
	for (j=0;j<i;j++) printf("%d ",a[j]);
	printf("\n");
}
int main(){
	char p;
	int a[10],i=0,x,c;
	do{
	
	printf("1:pop\n2:push\n3:print\n4:exit\n");
	scanf("%d",&c);
	switch(c){
		case 1: pop(&i); break;
		case 2: scanf("%d",&x); push(a,x,&i); break;
		case 3: print(a,i); break;
		default: break;
	};
	}while(c!=4);
	return 0;
}
