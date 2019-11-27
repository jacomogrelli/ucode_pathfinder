#include "pathfinder.h"

char **pf_uniq_matrix(char **matrix, int *isl_count) {
    char **buf = matrix;
    char **res = NULL;
    int count = 0;
    int k = 2;
    if (*isl_count >= 0)
    
    for (; buf[k] != NULL; k += 2) {
        for (int i = k; buf[i] != NULL; i++) {
            buf[i] = buf[i + 1];
            count = i;
        }
    }
    k = mx_bubble_sort(buf, count);
    for (int i = 0; buf[i + 1] != NULL; i++) {
        for (int j = i + 1; buf[j] != NULL; j++) {
            if (mx_strcmp(buf[i], buf[j]) == 0) {
                buf[i] = "del";
                i++;
                count--;
            }
        }
    }
    if (*isl_count != count) {
        mx_printerr("error: invalid number of islands\n");
        exit (-1);
    }
    res = malloc(sizeof(char *) * count);
        mx_print_strarr(buf, "__");
    for (int i = 0, j = 0; buf[j] != NULL; j++) {
        if (mx_strcmp(buf[j], "del") != 0) {
            res[i] = mx_strdup(buf[j]);
            i++;
        }
    }
    res[count] = NULL;
    // mx_del_strarr(&buf);
        printf("%d\n", *isl_count);

        mx_print_strarr(res, "\n");
 
    return res;
}

// || 
