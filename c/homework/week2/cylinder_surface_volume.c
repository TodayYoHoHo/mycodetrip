#include<stdio.h>
#define PI 3.1415926
main(){
	int r,h;
	double s,v;
	scanf("%d %d",&r,&h);
	s = 2*PI*r*h;
	v = PI*r*r*h;
	printf("s=%.2f,v=%.2f\n",s,v);
}
