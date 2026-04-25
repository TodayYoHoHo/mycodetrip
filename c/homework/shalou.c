#include <stdio.h>

int main() {
    int n;
    char ch;
    
    scanf("%d %c", &n, &ch);
    
    int i = 1;
    int used = 1;
    int max_chars = 1;
    
    while (1) {
        int next_row_chars = 2 * (i + 1) - 1;
        int needed = used + 2 * next_row_chars;
        
        if (needed > n) {
            break;
        }
        
        i++;
        used = needed;
        max_chars = 2 * i - 1;
    }
    int row,space,j;
    for (row = i; row >= 1; row--) {
        int chars_in_row = 2 * row - 1;
        
        for (space = 0; space < (max_chars - chars_in_row) / 2; space++) {
            printf(" ");
        }
        
        for (j = 0; j < chars_in_row; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    
    for (row = 2; row <= i; row++) {
        int chars_in_row = 2 * row - 1;
        
        for (space = 0; space < (max_chars - chars_in_row) / 2; space++) {
            printf(" ");
        }
        
        for (j = 0; j < chars_in_row; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    
    printf("%d\n", n - used);
    
    return 0;
}
