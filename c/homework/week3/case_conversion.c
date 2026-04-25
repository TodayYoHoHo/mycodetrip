#include<stdio.h>

main(){
	char a;
	a = getchar();
	if ('a'<=a && a<='z') a = a-32;
	else if ('A'<=a && a<='Z') a = a+32;
	putchar(a);
	putchar('\n');
}
