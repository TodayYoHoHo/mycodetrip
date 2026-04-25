#include<stdio.h>
#define N 5

int main(){
	int i, j, m, a[N];
	for (i=0; i<N; i++){
		scanf("%d",&a[i]);
	}
	for (i=0; i<N-1; i++){
		int p=i; //取最小值下标p
		for (j=i+1; j<N; j++){
			if (a[j] < a[p]) p = j;
		}
		if(i!=p){
			m = a[i];
			a[i] = a[p];
			a[p] = m;
		}
	}
	for (i=0;i<N;i++) printf("%d",a[i]);
}
