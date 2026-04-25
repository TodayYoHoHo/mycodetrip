#include<stdio.h>
int main(){
	int a1,a2,b1,b2,c1,c2,x = 2,y;
	int a3,a4,b3,b4,c3,c4;
	char op;
	scanf("%d/%d %c %d/%d",&a1,&a2,&op,&b1,&b2);
	a3 = a1;
	a4 = a2;
	b3 = b1;
	b4 = b2;
	if (op=='+'||op=='-') {
		c2 = a2 * b2;
		if (op=='+') c1 = a1 * b2 + b1 * a2;
		else c1 = a1 * b2 - b1 * a2;
	}
	else {
		if (op=='*') {
			c2 = a2*b2;
			c1 = a1*b1;
		}
		else {
			c2 = a2*b1;
			c1 = a1*b2;
		}
	}
	while (x<=c1) {
			if (c1%c2==0) {
				y=c1/c2;
				break;
			}
			else if ((c1%x==0) && (c2%x==0)) {
				c1 /= x;
				c2 /= x;
			}
			else x++;
		}
		if (c1%c2==0) printf("%d/%d %c %d/%d = %d\n",a1,a2,op,b1,b2,y);
		else printf("%d/%d %c %d/%d = %d/%d\n",a1,a2,op,b1,b2,c1,c2);
}

