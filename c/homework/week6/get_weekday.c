#include <stdio.h>


int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int get_days_in_month(int year, int month) {

    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month];
}

int main() {
    int y, m, d, n;

    scanf("%d %d %d", &y, &m, &d);
    scanf("%d", &n);

    d += n;

    while (d > get_days_in_month(y, m)) {

        d -= get_days_in_month(y, m);
        m++;

        if (m > 12) {
            m = 1;
            y++;
        }
    }

    printf("%d.%d.%d\n", y, m, d);

    return 0;
}