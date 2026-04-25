#include<stdio.h>


int main(){
	int h,i,x;
	scanf("%d",&h);
	for (i=1;i<=h;i++) {
		if (i==1){
			for (x=1;x<=2*h-1;x++){
				printf("*");
			}
			printf("\n");
		}
		else if(i==h){
			for (x=1;x<h;x++) {
				printf(" ");
			}
			printf("*\n");
		}
		else {
			for (x=1;x<i;x++) {
				printf(" ");
			}
			printf("*");
			for (x=1;x<=2*h-2*i-1;x++) {
				printf(" ");
			}
			printf("*\n");
		}
	}
	
}
