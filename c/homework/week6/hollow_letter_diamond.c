#include<stdio.h>

int main() {
    int n;
    char start;
    scanf("%c %d",&start,&n);
    char str[n];
    for (int i = 0; i < n; i++) {
        str[i] = start;
        start += 1;
    }
    for (int i=0;i<n;i++) {
        for (int x=0;x<n-1-i;x++) {printf(" ");}
        printf("%c",str[i]);
        for (int j=0;j<2*i-1;j++) {printf(" ");}
        if (i != 0) {printf("%c",str[i]);}
        printf("\n");
    }
    for (int i=0;i<n-1;i++) {
        for (int x=0;x<=i;x++) {printf(" ");}
        printf("%c",str[n-2-i]);
        for (int j=0;j<2*(n-2-i)-1;j++) {printf(" ");}
        if (i != n-2) {printf("%c",str[n-2-i]);}
        printf("\n");
    }
}