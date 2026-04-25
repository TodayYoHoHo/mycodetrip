#include<stdio.h>
main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	
	if (a>b) {
		if (b>c) ;
		else {
			int temp = b;
			b=c;
			c=temp;
		}
		
	}
	else {
		int temp = a;
		a=b;
		b=temp;
		if (b>c) ;
		else{
			int temp = b;
			b=c;
			c=temp;
		}
	}
	
	
	if ((b+c>a) && (c+a>b)) {
		if(a==b && b==c) printf("equilateral triangle.\n");
		else if((a==b) || (b==c) || (a==c)) printf("isoceles triangle.\n");
		else printf("triangle.\n");
	}
	
	else printf("non-triangle.\n");
	
	
}
