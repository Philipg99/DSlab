#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isexp(char a){
	if( a=='+' || a=='-' || a=='*' || a=='/' || a=='^') return true;
	return false;	
}
bool isperen(char a){
	if( a=='(' || a==')')return true;
	return false;
}
bool isvar(char a){
	if( !(isexp(a) || isperen(a)) ) return true;
	return false;
}
int pri(char a){
	if (a=='^') return 3;
	if (a=='*' || a=='/') return 2;
	if (a=='+' || a=='-') return 1;
	return 0;
}

int main(){
	char in[100],post[100],stack[100];
	int ip,pp=0,sp=1,i;
	scanf("%s",in);
	stack[0]='(';

	for(ip=1;ip<=strlen(in);ip++){
		if ( isvar(in[ip]) ) post[pp++]=in[ip];

		if ( isperen(in[ip]) ) if (in[ip]=='(') stack[sp++]+='(';
		else {while (stack[sp-1]!='(') post[pp++]=stack[--sp]; sp--;}

		if ( isexp(in[ip]) ){ 
		while ( pri(in[ip])<pri(stack[sp-1]) ) post[pp++]=stack[--sp]; 
		stack[sp++]=in[ip];
		}
	}

	for(i=0;i<pp;i++) printf("%c",post[i]);
	printf("\n");
	
	return 0;
}
