#include<stdio.h>

int main(){
	int a[10],i,j,t;
	for(i=0;i<10;i++)
		scanf("%d",a+i);

	
	for(i=0;i<9;i++)
		for(j=0;j<10;j++)
			if(a[i]<a[j]){
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
	
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
