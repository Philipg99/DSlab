#include<stdio.h>
#include<string.h>
#include<stdbool.h>

float pw(float a, float b){
	float r=1;
	for(;b>0;b--) r*=a;
	return r;
}

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

float getval(float v[], char a){ return v[(int)a-97 ];}

float cal(float v[],char a,char b,char c){
	if(c=='+') return getval(v,a)+getval(v,b);
	if(c=='-') return getval(v,a)-getval(v,b);
	if(c=='*') return getval(v,a)*getval(v,b);
	if(c=='/') return getval(v,a)/getval(v,b);
	if(c=='^') return pw(getval(v,a),getval(v,b));
	
}

int main(){
	float v[26];
	int nvar,i,vp=0,op=1,j;
	char eqn[100],ops[100],var[100];
	printf("enter the number of variables: "); scanf("%d",&nvar);
	printf("enter the variables: ");for(i=0;i<nvar;i++) scanf("%f",v+i);
	printf("enter expertion: ");scanf("%s",eqn);
	ops[0]='(';
	for(i=1;i<strlen(eqn);i++){
		if (isvar(eqn[i])) var[vp++]=eqn[i];

		if (isexp(eqn[i])) 
			if (pri(eqn[i])>=pri(ops[op-1])) 
				ops[op++]=eqn[i];
			else{
				while ( pri(eqn[i])<pri(ops[op-1] )) {
				v[(int)var[vp-2]-97] = cal(v,var[vp-2],var[vp-1],ops[op-1]); 
				op--;vp--;}
			ops[op++]=eqn[i];
			}
		
		if (isperen(eqn[i])) 
			if (eqn[i]=='(') ops[op++]=eqn[i];
			else {
				while (ops[op-1]!='(') {	
					v[(int)var[vp-2]-97] = cal(v,var[vp-2],var[vp-1],ops[op-1]); 	
					op--;vp--;}
			op--;
			}
	}

	printf("%f\n",getval(v,var[0]));
		

	return 0;
}
