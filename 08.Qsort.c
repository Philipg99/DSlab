#include<stdio.h>

int quick(int a[],int l,int h){
    int piv=l,t=0;
    while (l<h){
        while (a[h]>a[piv] && h>l) h-=1;
        while (a[l]<=a[piv] && l<h) l+=1;
        if (l<h){
            t=a[l];
            a[l]=a[h];
            a[h]=t;
	}
	}
    t=a[piv];
    a[piv]=a[l];
    a[l]=t;
    return l;
}

void part(int a[],int l,int h){	
    int j=0;
    if (l<h){
	j=quick(a,l,h);
	part(a,l,j-1);
	part(a,j+1,h);
    }
    
}

int main(){
	int a[]={23,35,345,7647,2,356,78,23,5},i;
	part(a,0,8);
	for(i=0;i<9;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
