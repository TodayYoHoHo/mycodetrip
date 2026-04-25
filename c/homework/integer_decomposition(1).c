#include<stdio.h>

int main(){
	int n,sum,i,j;
	scanf("%d",&n);
	for (i=1;i<n;i++){
		j=i;
		sum=0;
		while (sum<n){
			sum+=j;
			j++;
		}
		if (sum==n){
			printf("%d~%d\n",i,j);
		} 
	}
}
