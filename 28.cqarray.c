#include <stdio.h>
#define size 5

int f=-1,r=-1;

void print(int a[])
{
	int i;
	if (f>r){
		for(i=f;i<size;i++) printf("%d ",a[i]);
		for(i=0;i<=r;i++) printf("%d ",a[i]);
	}
	else for (i=f;i<=r;i++) printf("%d ",a[i]);
	printf("\n");
}

void deq()
{
	if(f!=r) f=(f+1)%size;
	else if (f==r) f=r=-1;
}

void enq(int a[],int x)
{	
	if (f==-1) {f=r=0;a[0]=x;}
	else if((r+1)%size!=f) {r=(r+1)%size; a[r]=x;}
}


int main()
{
    int n,i;
    char ch;
    int a[size]={0,0,0,0,0};
    do
    {
	getchar();
        printf("\ni:Insert d:Delete p:Print e:Exit :",);
        scanf("%c", &ch);
        switch (ch)
        {
            case 'i':
                scanf("%d", &n);
                enq(a, n);
                break;
            case 'd':
                deq();
                break;
            case 'p':
                print(a);
                break;
        }
    }while (ch != 'e');
}



