#include<stdio.h>
int main(){
	int n,i,x,flag=0;
	scanf("%d",&n);
	for (i=5;i<=n/2;i++){
		int counter = 0;
		for (x=1;x<=i;x++) {  
            if (i%x==0) counter++;  
        }  
        if (counter==2) {
        	counter = 0;
			for (x=1;x<=n-i;x++) {  
            if (i%x==0) {
				counter++;
			} 
			if (counter==2){
				printf("%d+%d=%d\n",i,n-i,n);
				flag = 1;
				break;
			}
        }  
        }
        if (flag==1) break;
	}
}


