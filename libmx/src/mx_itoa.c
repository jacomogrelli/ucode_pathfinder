#include "libmx.h"

char *mx_itoa(int number) {
    char *res = mx_strnew(12);
    int i = 0;
    int min_check = number;

    if (number == -2147483648) {
        res[0] = '8';
        i = 1;
        number = -214748364;
    }
    if (number < 0)
        number *= -1;
    if (number == 0)
        res[0] = '0';
    while(number > 0) {
        res[i] = number % 10 + '0';
        number = number / 10;
        i++;
    }
    if (min_check < 0)
        res[i] = '-';
    free(res);
    mx_str_reverse(res);
    return res;
}
