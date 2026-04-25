#include <stdio.h>
#include <string.h>

int main () {
    int k=0;
    char a[100];
    scanf("%s",a);
    int i, j, length=strlen(a);
    for (i=0; i<length-1; i++) {
        int p = i;
        for (j=i+1; j<length; j++) {
            if (a[p] < a[j]) p=j;
        }
        if (p != i) {
            char m = a[p];
            a[p] = a[i];
            a[i] = m;
        }
    }
    printf("%s\n",a);
}
