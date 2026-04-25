#include<stdio.h>
int main(){
	int n,m,sum=0;
	m=1;
	scanf("%d",&n);
	while (sum<n)
	{
		sum+=m;
		m++;
	}
	printf("%d\n",m-1);
}
