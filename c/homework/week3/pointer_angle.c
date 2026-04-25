#include<stdio.h>
#include<math.h>


int main(){
	float angle_h,angle_m,angle;
	int h,m,h_1; 
	scanf("%d %d",&h,&m);
	h_1 = h;
	h = h%12;
	angle_h = h*30.0f + m* 0.5f;
	angle_m = m*6.0f;
	angle = fabs(angle_m - angle_h);
	if (angle > 180.0f){
		angle = 360.0f - angle;
	}
	
	printf("At %d:%02d the angle is %.1f degrees.\n",h_1,m,angle);
}
