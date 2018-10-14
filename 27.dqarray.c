#include<stdio.h>

void deqf(int a[],int *i){
	int j;
	if (*i>0) {for(j=1;j<*i;j++) a[j-1]=a[j]; (*i)--;}
	else printf("empty queue\n");		
}
void deqb(int a[],int *i){
	int j;
	if (*i>0) (*i)--; 
	else printf("empty queue\n");	
}
void enqf(int a[],int x,int *i){
	int j;
	if (*i<10) {for(j=(*i)-1;j>=0;j--) a[j+1]=a[j]; (*i)++; a[0]=x;}
	else printf("empty queue\n");	

}
void enqb(int a[],int x,int *i){
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
	int a[10],i=0,x,q,e;
	
	do{
	getchar(); 
	printf("e:enqueue\nd:dequeue\np:print\nx:exit\n");
	scanf("%c",&c);
	printf("1:front 2:back");
	scanf("%d",&e);
	switch(c){
		case 'd': if (e==1) deqf(a,&i);else deqb(a,&i); break;
		case 'e': scanf("%d",&x); if (e==1) enqf(a,x,&i); else enqb(a,x,&i); break;
		case 'p': print(a,i); break;
		default: break;
	};
	}while(c!='x');
	return 0;
}
