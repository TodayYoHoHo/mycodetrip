#include<stdio.h>

int main() {
    int max,i,counter=0,x,res=0;
    scanf("%d",&max);
    for(i=max/4*3;i<=max;i++) {
        for (x=1;x<=i;x++) {
            if (i%x==0) counter++;
        }
        if (counter==2) res = i;
        counter = 0;
    }
    printf("The max prime number is %d.\n",res);
}