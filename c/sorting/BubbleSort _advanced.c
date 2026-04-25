# include<stdio.h>
 #define N 4
 
 int main(){
 	int i, j, m, a[N], end=0; //加入end判断，当顺序排好，无交换时不在重复排序
 	for(i=0; i<N; i++)
 		scanf("%d",&a[i]);
 	for(j=1; j<N && !end; j++)
 	{	end = 1;
 		for(i=0; i<N-j; i++)
 			if(a[i]<a[i+1]) {
 				m = a[i+1];
 				a[i+1] = a[i];
 				a[i] = m;
 				end = 0; 
 			}	
	}
 	for (i=0; i<N; i++) printf("%d",a[i]);
 	return 0;
 }
