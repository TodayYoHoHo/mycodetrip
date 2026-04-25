#include<stdio.h>

int main(){
	int i,n,x,a,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++){//上半部分递增
		// for (x=1;x<=n+i-1;x++) {//第i行有n+i-1个数
		j = 1;
		// x = 1;
		for (j; j<= n-i; j++) {
			printf("  ");//打印空格
			}
		for (j=0;j<i;j++) {
			printf("%-2d",n-j);
		}
		a =n-i+2;
		for (j=0;j<i-1;j++){
			printf("%-2d",a);
			a++;
		}
		printf("\n");
	}
	for (i=n+1;i<=2*n-1;i++) {
		// j = 1;
		for (j = 1; j<=i-n; j++) {
			printf("  ");//打印空格
		}
		for (j=0;j<2*n-i;j++){
			printf("%-2d",n-j);
		}
		a =i+2-n;
		for (j=0;j<2*n-i-1;j++){
			printf("%-2d",a);
			a++;
		}

		printf("\n");
	}
}
