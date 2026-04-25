#include<stdio.h>

int main() {
    int y, m, d, d_after, total_this_year = 365;
    scanf("%d %d %d", &y, &m, &d);
    scanf("%d", &d_after);
    //判断平闰年
    if ((y%4==0 && y%100!=0)||y%400==0) {
        total_this_year = 366;
        
    }
}
