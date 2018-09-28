#include<stdio.h>
#include <stdlib.h>

int main(){
	int a[10],b[10],c[10],i;

	printf("enter a,b,c...in the pollynomical ax^0+bx^2....jX^9\n");
	for(i=0;i<10;i++) scanf("%d",a+i);
	for(i=0;i<10;i++) scanf("%d",b+i);
	for(i=0;i<10;i++) c[i]=a[i]+b[i];
	for(i=0;i<10;i++) printf("%dx^%d ",c[i],i);

	return 0;
}
