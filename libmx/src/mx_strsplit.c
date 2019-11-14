#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    int len_el = 0;
    int size = 0;
    int res_count = 0;
    char **res = NULL;

    if (!s) return NULL;
    size = mx_count_words(s, c);
    res = (char**)malloc(sizeof(char*) * size); 
    for (int i = 0; res_count < size; i++) {
        if (s[i] == c && s[i]) 
            while (s[i] == c && s[i]) i++;
        if (s[i] != c && s[i]) {
            while (s[i] != c && s[i]) len_el++, i++;
            res[res_count] = mx_strndup(s + i - len_el, len_el);
            len_el = 0;
            res_count++;
        }
    }
    res[size] = NULL;
    return res;
}
