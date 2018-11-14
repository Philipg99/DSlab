#include<stdio.h>

void deq(int a[],int *i){
	int j;
	if (*i>0) {for(j=1;j<*i;j++) a[j-1]=a[j]; (*i)--;}
	else printf("empty queue\n");		
}

void enq(int a[],int x,int *i){
	if (*i<10) a[(*i)++]=x;
	else printf("full queue\n");
}

void print(int a[],int i){
	int j;
	for (j=0;j<i;j++) printf("%d ",a[j]);
	printf("\n");
}
int main(){
	char c;
	int a[10],i=0,x;
	printf("e:enqueue\nd:dequeue\np:print\nx:exit\n");
	do{
	getchar(); 
	scanf("%c",&c);
	switch(c){
		case 'd': deq(a,&i); break;
		case 'e': scanf("%d",&x); enq(a,x,&i); break;
		case 'p': print(a,i); break;
		default: break;
	};
	}while(c!='x');
	return 0;
}
