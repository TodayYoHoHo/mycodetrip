#include<stdio.h>
#include<math.h>
int main(){
	int n,i,flag=0;
	scanf("%d",&n);
	i=pow(10,n-1);
	while (i<=(pow(10,n)-1))
	{
		int digit,cnt=0,k=i,sum=0;
		while (k>0){
			digit = k%10;
			k/=10;
			sum += round(pow(digit,n));
			cnt++;
		}
		if (i==sum) {
		printf("%d\n",i);
		flag = 1;
		}
		i++;
	}
	if(flag==0) printf("No output.\n") ;
}
