#include<stdio.h>

int main(){
	int a[10],i,x;
	for(i=0;i<10;i++)
		scanf("%d",a+i);

	scanf("%d",&x);
	
	for(i=0;i<10;i++)
		if(a[i]==x){
			printf("Found at Index %d\n",a[i]);
			return 0;
		}
	
	printf("Not in List\n");
	return 0;
}
