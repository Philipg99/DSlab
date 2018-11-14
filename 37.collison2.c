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
				i=0;
				scanf("%ld",&num);
				while(ht[(hash(num)+i*i)%100]!=LONG_MIN){
					if (ht[(hash(num)+i*i)%100]==num){ printf("found");break;}
					i++;
				}
				
				break;
			case 'i':
				i=0;
				scanf("%ld",&num);
				while(ht[(hash(num)+i*i)%100]!=LONG_MIN && ht[(hash(num)+i*i)%100]!=LONG_MAX  ) i++;
				ht[(hash(num)+i*i)%100]=num;
				break;
			case 'd':
				i=0;
				scanf("%ld",&num);
				while(ht[(hash(num)+i*i)%100]!=LONG_MIN){
					if (ht[(hash(num)+i*i)%100]==num){ht[(hash(num)+i*i)%100]=LONG_MAX ;break;}
					i++;
				}

		};
	}while(x!='e');	
	
	return 0;
}
