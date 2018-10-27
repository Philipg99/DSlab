#include<stdio.h>

int main(){
	int a[10],i,j,t;
	for(i=0;i<10;i++)
		scanf("%d",a+i);

	
	for(i=9;i>0;i--)
		for(j=0;j<i;j++)
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
