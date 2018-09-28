#include<stdio.h>
#include <stdlib.h>

int main(){
	long a[5],b[5],c[10],i,j;
	for(i=0;i<10;i++) c[i]=0;
	printf("enter a,b,c...in the pollynomical ax^0+bx^2....jX^9\n");
	for(i=0;i<5;i++) scanf("%ld",a+i);
	for(i=0;i<5;i++) scanf("%ld",b+i);
	for(i=0;i<5;i++) for (j=0;j<5;j++) c[i+j]+=a[i]*b[j];
	for(i=0;i<10;i++) printf("%ldx^%ld ",c[i],i);
	printf("\n");

	return 0;
}
