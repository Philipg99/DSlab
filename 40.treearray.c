#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

int tree[1024];


void print(int ptr){
	printf("(");
	if (tree[ptr*2+1]!=INT_MIN) print(ptr*2+1);
	printf(" %d ",tree[ptr]);
	if (tree[ptr*2+2]!=INT_MIN) print(ptr*2+2);
	printf(")");
}

int scan(int ptr,int i){
	if (ptr!=INT_MIN){
		if (tree[ptr]==i) return ptr;
		if (tree[ptr]<i) scan(ptr*2+2,i);
		else if (tree[ptr]>=i) scan(ptr*2+1,i);}
	else return INT_MIN;
}



void insert(int ptr,int i){

	if(tree[ptr]<i) 
		if (tree[ptr*2+2]!=INT_MIN) insert(ptr*2+2,i);
		else tree[ptr*2+2]=i;
	else 
		if (tree[ptr*2+1]!=INT_MIN) insert(ptr*2+1,i);
		else tree[ptr*2+1]=i;
 	
}

int min(int ptr){

}

void delete(int ptr){
	int tmp;
	if(tree[ptr*2+1]==INT_MIN && tree[ptr*2+2]==INT_MIN){
		tree[ptr]=INT_MIN;
		return;}
	else if(tree[ptr*2+2]!=INT_MIN){
		tmp=ptr*2+2;
		while (tree[tmp*2+1]!=INT_MIN) tmp=tmp*2+1;
		tree[ptr]=tree[tmp];
		delete(tmp);
	}
	else if(tree[ptr*2+1]!=INT_MIN){
		tmp=ptr*2+1;
		while (tree[tmp*2+2]!=INT_MIN) tmp=tmp*2+2;
		tree[ptr]=tree[tmp];
		delete(tmp);
	}
	
}
	
int main(){
	int i ;
	char x;
	for(i=0;i<1024;i++) tree[i]=INT_MIN;
	do{
		scanf("%c",&x);
		switch(x){
			getchar();
			printf("i:insert s:scan d:delete p:print e:exit:");
			case 's':
				scanf("%d",&i);
				if (scan(0,i)!=INT_MIN) printf("found");
				break;
			case 'i':
				scanf("%d",&i);
				if (tree[0]==INT_MIN) tree[0]=i;
				else insert(0,i);
				break;
			case 'd':
				scanf("%d",&i);
				delete(scan(0,i));
				break;
			case 'p':
				print(0);
				printf("\n");
				break;
		};
	}while(x!='e');
	return 0;

}
