#include<stdio.h>
int main(){
	int n=0,n1,n2;
	scanf("%d",&n);
	for (n1=1;n1<=n;n1++){
		for (n2=(n1-1)*n+1;n2<=n1*n;n2++){
			printf("%3d",n2);
		}
		printf("\n");
	}
}
