#include <stdio.h>
#define size 5

int f=-1,r=-1;

void print(int queue[])
{
    int i;
    printf("\n");
    if (f > r){
        for (i = f; i < size; i++) printf("%d ", queue[i]);
        for (i = 0; i <= r; i++) printf("%d ", queue[i]);
    }
    else for (i = f; i <= r; i++) printf("%d ", queue[i]); 
}

void deq(int queue[])
{
    if (f ==  - 1) printf("Queue is empty ");
    else if (f == r){
        printf("\n %d deleted", queue[f]);
        f = - 1;
        r = - 1;
    }
    else printf("\n %d deleted", queue[f++]);

}

void enq(int queue[],int item)
{
    if ((f == 0 && r == size - 1) || (f == r + 1)){ printf("queue is full"); return;}
    else if (r ==  - 1) { r++; f++; }  
    else if (r == size - 1 && f > 0) r = 0;
    else r++;
    queue[r] = item;
}


int main()
{
    int n, ch;
    int queue[size];
    do
    {
        printf("\n\n Circular Queue:\n1. Insert \n2. Delete\n3. Display\n0. Exit");
        printf("\nEnter Choice 0-3? : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                enq(queue, n);
                break;
            case 2:
                deq(queue);
                break;
            case 3:
                print(queue);
                break;
        }
    }while (ch != 0);
}



