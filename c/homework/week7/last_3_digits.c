#include <stdio.h>

int main() {
    long res = 1;
    int a, n, res_1;
    scanf("%d %d",&a, &n);
    if (n == 0) printf("The last 3 numbers is 1.\n");
    else {
        int cnt = 0;
        while (cnt < n) {
            cnt++;
            res = (res%1000) * a;
        }
        res_1 = res % 1000;
        if (res_1 == 0) printf("The last 3 numbers is 000.\n");
        else printf("The last 3 numbers is %d.\n", res_1);
    }
}