#include<stdio.h>

int main(){
	int a,b,x,output;
	char op;
	scanf("%d%c%d",&a,&op,&b);
	if (op=='+') x=1;
	else if (op=='-') x=2;
	else if (op=='*') x=3;
	else if (op=='/') x=4;
	
	switch(x){
		case 1: output = a+b;break;
		case 2: output = a-b;break;
		case 3: output = a*b;break;
		case 4: output = a/b;break;
		default:break;
	}
	printf("%d\n",output);
	
}
