#include<stdio.h>


int main() {
    while (1){
        int x_l,x_r,counter=0,num[4];
        scanf("%d %d",&x_l,&x_r);
        if (x_l/1000!=0 && x_l/10000==0 && x_r/1000!=0 && x_r/10000==0) {
            int res[x_r-x_l+1];
            for (int i=x_l;i<=x_r;i+=2) {
                int x=i;
                for (int n=0;n<4;n++) {
                    num[n] = x%10;
                    x /= 10;
                }
                if ((num[0]!=num[1])&&(num[1]!=num[2])&&(num[2]!=num[3])&&(num[0]!=num[2])&&(num[0]!=num[3])&&(num[1]!=num[3])) {
                    res[counter] = i;
                    counter++;
                }
            }
            if (counter==0) {printf("\n");printf("0");continue;}

            for (int i=0;i<counter;i++) {
                printf("%d  ",res[i]);
            }
            printf("\n");
            printf("counter=%d\n",counter);
        }
        else if(x_l==0&&x_r==0) break;
        else {printf("Error\n");continue;}
    }
}