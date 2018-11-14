#include<stdio.h>
#include<limits.h>

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
	long ht[100],num,i;
	for(i=0;i<100;i++) ht[i]=LONG_MIN;
	printf("i:insert s:scan d:delete e:exit\n");
	do{	
		scanf("%c",&x);
		switch(x){
			case 's':
				scanf("%ld",&num);
				if(ht[hash(num)%100]==num) printf("found\n");
				break;
			case 'i':
				scanf("%ld",&num);
				ht[hash(num)%100]=num;
				break;
			case 'd':
				scanf("%ld",&num);
				ht[hash(num)%100]=LONG_MIN;
				break;

		};
	}while(x!='e');	
	
	return 0;
}
