#include<stdio.h>

int main() {
    int min=9,max=0,a,res;
    char op,op1 = 0;
    while ((op = getchar())!= '=') {
        if (op<='9' && op>='0') {
            a = op - '0';
            if (a>=max) max = a;
            if (a<=min) min = a;
        }
        else if (op == ',') continue;
        else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') op1 = op;
    }
    if (op1 == '+') {
        res = max + min;
        printf("%d%c%d=%d\n",max,op1,min,res);
    }
    else if (op1 == '-') {
        res = max - min;
        printf("%d%c%d=%d\n",max,op1,min,res);
    }
    else if (op1 == '*') {
        res = max * min;
        printf("%d%c%d=%d\n",max,op1,min,res);
    }
    else if (op1 == '/') {
        if (min == 0) printf("Error!\n");
        else {
            res = max / min;
            printf("%d%c%d=%d\n",max,op1,min,res);
        }
    }
    else if (op1 == '%') {
        if (min == 0) printf("Error!\n");
        else {
            res = max % min;
            printf("%d%c%d=%d\n",max,op1,min,res);
        }
    }
}