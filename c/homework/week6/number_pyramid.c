#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n-i; k++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%2d", j);
        }
        for (int j = i-1; j > 0; j -= 1) {
            printf("%2d", j);
        }
        printf("\n");
    }
}