#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, x1, x2;
    double d;

    scanf("%f %f %f", &a, &b, &c);

    if (a==0) {
        if (b==0) {
            printf("Input error!\n");
        }
		else {
            x1 = -c / b;
            if (c==0) printf("x=%f\n", -x1);
            else printf("x=%f\n", x1);
        }
    } 
	else {
        
        d = b * b - 4 * a * c; 
        if (d==0) {
            x1 = x2 = -b / (2 * a);
            if (c==0) printf("x1=x2=%f\n", -x1);
            else printf("x1=x2=%f\n", x1);
        } 
		else if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            printf("x1=%f\nx2=%f\n", x1, x2);
        } 
		else {
            double real = -b / (2.0 * a);
            double imag = sqrt(-d) / (2.0 * a);
            if (real==0) printf("x1=%fi\nx2=-%fi\n",imag,imag);
            else printf("x1=%f+%fi\nx2=%f-%fi\n", real, imag, real, imag);
        }
    }

    return 0;
}
