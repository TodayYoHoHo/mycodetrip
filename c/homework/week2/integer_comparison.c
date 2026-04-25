# include<stdio.h>
main() {
	int a,b;
	scanf("%d %d",&a,&b);
	if (a>=b) printf("min=%d\n",b);
	if (a<b) printf("min=%d\n",a);
}
