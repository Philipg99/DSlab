#include<stdio.h>
#define n 5
void solve(int a[5][5], int i,int j){
	a[i][j]=2;
	if (i==4 && j==4) printf("solved\n");
	if (j+1<5)if (a[i][j+1]==1) solve(a,i,j+1);
	if (i+1<5)if (a[i+1][j]==1) solve(a,i+1,j);
	if (j-1>=0)if (a[i][j-1]==1) solve(a,i,j-1);
	if (i-1>=0)if (a[i-1][j]==1) solve(a,i-1,j);
	
}


int main(){
	int a[5][5]={{1,0,1,1,1},
		     {1,0,1,0,1},
		     {1,0,1,0,1},
		     {1,0,1,0,1},
		     {1,1,1,0,1}};
	solve(a,0,0);
	return 0;
}
