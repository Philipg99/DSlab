#include<stdio.h>


void merge(int a[],int l,int h){
	int t[h-l+1],m=(h+l)/2,s=l,i=0,k=0,mh=(h+l)/2+1;

	while (l<=m && mh<=h)
                if (a[l]<a[mh])
                	        t[k++]=a[l++];
                else
                	        t[k++]=a[mh++];

        while (l<=m)
		t[k++]=a[l++];

	while (mh<=h)
                t[k++]=a[mh++];
	
	for (i=s;i<=h;i++)
		a[i]=t[i-s];
		
}

void split(int a[],int l, int h){
	int m=(h+l)/2;
	if (l<h){
		split(a,l,m);
		split(a,m+1,h);
		merge(a,l,h);
	}
}


int main(){
	int a[]={23,35,345,7647,2,356,78,23,5},i;
	split(a,0,8);
	for(i=0;i<9;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
