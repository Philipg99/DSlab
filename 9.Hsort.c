#include<stdio.h>
#include<math.h>

void heapify(int a[],int n,int i){
    int large=i,l=2*i+1,r=2*i+2,t=0;

    if (l<=n && a[large]<a[l]) large=l;
    if (r<=n && a[large]<a[r]) large=r;

    if (large!=i){
        t=a[i];
        a[i]=a[large];
        a[large]=t;
        if (large<=n/2) heapify(a,n,large);
    }
}

void heapsort(int a[],int n){
    int t=0,i;
    for (i=n/2;i>0;i--) heapify(a,n,i);

    for (i=n;i>0;i--){
            t=a[i];
            a[i]=a[0];
            a[0]=t;
            heapify(a,i-1,0);
    }
}

int main(){
	int a[]={23,35,345,7647,2,356,78,23,5,5764,657657,345,365235,542,88,234},i;
	heapsort(a,15);
	for(i=0;i<16;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
