#include<stdio.h>

int main() {
    int n, tol=1;
    scanf("%d", &n);
    int N = n;
    for (int i=1; i<N; i++) {
        tol = 2 * (tol + n -1);
        n--;
    }
    if (tol == 1) printf("The monkey got %d peach in first day.\n", tol);
    else printf("The monkey got %d peaches in first day.\n", tol);
}