#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *buf1 = NULL;
    char *buf2 = NULL;
    int len_str = 0;
    int len_sub = 0;
    int len_replace = 0;

    if (!str || !sub || !replace)
        return NULL;
    len_str = mx_strlen(str);
    len_sub = mx_strlen(sub);
    len_replace = mx_strlen(replace);
    buf1 = mx_strnew((const int)len_str + (len_replace - len_sub) * mx_count_substr(str, sub));
    buf2 = buf1;

    while (*str) {
        if (str != mx_strstr(str, sub)) {
            *buf2 = *str;
            buf2++, str++;
        }
        if (str == mx_strstr(str, sub)) {
            buf2 = mx_strcat(buf2, replace);
            buf2 += len_replace;
            str += len_sub;
        }
    }
    return buf1;
}
