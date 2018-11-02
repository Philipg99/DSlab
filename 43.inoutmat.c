#include<stdio.h>
#include<stdlib.h>

int main(){
	int m[10][10],in[10],out[10],n,i,j,x,y;
	for(i=0;i<10;i++) for(j=0;j<10;j++) m[i][j]=0;
	for(i=0;i<10;i++) in[i]=out[i]=0;
	printf("enter the number of vertexes(max 10):");
	scanf("%d",&n);
	printf("enter the number of conections:");
	scanf("%d",&i);
	printf("enter the conections:\n");
	while(i>0){
		i--;
		scanf("%d %d",&x,&y);
		m[x][y]=1;
	}
	for(i=0;i<10;i++) for(j=0;j<10;j++) if (m[i][j]==1){in[j]++; out[i]++;}
	printf("Indegree ");
	for(i=0;i<n;i++) printf("%d:%d ",i,in[i]);
	printf("\nOutdegree ");
	for(i=0;i<n;i++) printf("%d:%d ",i,out[i]);
	printf("\n");
	return 0;
}
