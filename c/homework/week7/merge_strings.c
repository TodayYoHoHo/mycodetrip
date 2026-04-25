#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    int i=0, j=0 ,k=0;
    gets(a);
    gets(b);
    // scanf("%99s",a);
    // scanf("%99s",b);
    int a_len = strlen(a);
    int b_len = strlen(b);
    char res[a_len + b_len + 1];
    while (a[i] != '\0' && b[j] != '\0') {
        if (a[i] < b[j]) {
            res[k++] = a[i++];
        }
        else {
            res[k++] = b[j++];
        }
    }
    while (a[i] != 0) {
        res[k++] = a[i++];
    }
    while (b[j] != 0) {
        res[k++] = b[j++];
    }
    res[k] = '\0';
    puts(res);
    return 0;
}
