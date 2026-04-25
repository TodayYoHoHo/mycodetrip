#include<stdio.h>

int main() {
    int n, num_a = 0, num_b = 0, num_c=0, len_a = 0, len_b = 0, len_c = 0;
    scanf("%d",&n);
    while (num_a + num_b * 0.5 + num_c * 0.1 < 10*n) {
        num_a ++;
        len_a = num_a*20;
        num_b = 0;
        num_c = 0;
        while (len_b < len_a) {
            num_b ++;
            len_b = num_b * 15;
        }
        while (len_c < len_a) {
            num_c ++;
            len_c = num_c * 18;
        }

    }
    if (len_a == len_b && len_b == len_c) {
        if (10*n == num_a + num_b * 0.5 + num_c * 0.1) {
            printf("%d,%d,%d\n",num_c,num_b,num_a);
        }
        else printf("No change.\n");
    }
    else printf("No change.\n");

}