#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

long hash(long n){
	int sum=0;
	while (n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
	
}

int main(){

	char x;
	long *ht,*tmp,l=10,num,i;
	ht=(long*)calloc(l,sizeof(long));
	for(i=0;i<l;i++) ht[i]=LONG_MIN;
	printf("i:insert s:scan d:delete e:exit\n");
	do{	
		scanf("%c",&x);
		switch(x){
			case 's':
				scanf("%ld",&num);
				if (hash(num)<l) if(ht[hash(num)]==num) printf("found\n");
				break;
			case 'i':
				scanf("%ld",&num);
				if (hash(num)>=l){
					tmp=(long*)calloc(hash(num)+1,sizeof(long));
					for(i=0;i<l;i++) tmp[i]=ht[i];
					for(i=l;i<hash(num)+1;i++) tmp[i]=LONG_MIN;
					free(ht);
					l=hash(num)+1;
					ht=tmp;
				}
				ht[hash(num)]=num;
				break;
			case 'd':
				scanf("%ld",&num);
				if (hash(num)<l) ht[hash(num)]=LONG_MIN;
				break;

		};
	}while(x!='e');	

	return 0;
}







