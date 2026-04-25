# include<stdio.h>
 #define N 4
 
 int main(){ //冒泡排序
 	int i, j, a[N];
 	for(i=0;i<N;i++)
 		scanf("%d",&a[i]);
 	for(j=1;j<N;j++) //循环n-1次
 		for(i=0;i<N-j;i++) //第j次只用循环n-j次
 			if(a[i]<a[i+1]) { //交换取值
 				int m = a[i+1];
 				a[i+1] = a[i];
 				a[i] = m;
 			}
 	for (i=0;i<N;i++) printf("%d",a[i]);
 	return 0;
 }
