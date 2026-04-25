#include<stdio.h>
int main(){
	//获取当前星期
	int n,y,r;
	//用于计算天数的n1,天数days,二月天数x
	int n1=1900,days=0,x; 
	scanf("%d %d %d",&n,&y,&r);
	//按年计算天数
	while (n1<n) {
		if(((n1%4)==0 && (n1%100!=0)) || (n1%400 ==0)) days+=366;
		else days+=365;
		n1++;
	}
	if (((n%4)==0 && (n%100!=0)) || (n%400 ==0)) x = 29;
	else x=28;
	//当年天数 
	switch(y-1){
		case 12:days += 31;
		case 11:days += 30;
		case 10:days += 31;
		case 9:days += 30;
		case 8:days += 31;
		case 7:days += 31;
		case 6:days += 30;
		case 5:days += 31;
		case 4:days += 30;
		case 3:days += 31;
		case 2:days += x;
		case 1:days += 31;break;
		default :break;
	}
	days += r;
	printf("%d\n",days%7);
	
} 
