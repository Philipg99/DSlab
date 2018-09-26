#include<stdio.h>

int main(){
	int a[10],i,x,h=10,l=0,m;
	for(i=0;i<10;i++)
		scanf("%d",a+i);

	scanf("%d",&x);

	while(l<h){
		m=(h+l)/2;
		if (a[m]==x){
			printf("found in index %d\n",m);
			return 0;
		}
		if (a[m]<x)
			l=m+1;
		else
			h=m-1;
	}
	printf("not found");
	printf("\n");
	return 0;
}
