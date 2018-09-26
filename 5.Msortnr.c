#include<stdio.h>

int min(int a,int b){
	if (a<b) return a;
	return b;
}

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

void split(int a[],int size){
	int width=1,l,h;

	while(width<size){
		l=0;

		while (l<size){
			h=min(2*width+l-1,size);
			merge(a,l,h);
			l+=width*2;
		}

		width*=2;
	}
}


int main(){
	int a[]={23,35,345,7647,2,356,78,23,5,5764,657657,345,365235,542,88,234},i;
	split(a,15);
	for(i=0;i<16;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
