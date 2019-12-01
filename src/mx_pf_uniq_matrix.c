#include "pathfinder.h"

static void pf_error_num(int i, int isl);

char **mx_pf_uniq_matrix(char **matrix, int *isl_count) {
    char **res = malloc(sizeof(char *) * *isl_count);
    int i = 1;

    res[0] = mx_strdup(matrix[0]);
    for (int k = 1; matrix[k] != NULL; k++) {
        pf_error_num(i, *isl_count);
        for (int j = 0; j != k && mx_strcmp(res[j], matrix[k]) != 0; j++) {
            if (j + 1 == k) {
                res[i] = mx_strdup(matrix[k]);
                i++;
            }
        }
        if (k == 11)
        mx_print_strarr(res, "\n");
        if (matrix[k + 1] == NULL)
            break;
    }
    return res;
}

static void pf_error_num(int i, int isl) {
    if (i == isl) {
        mx_printerr("error: invalid number of islands\n");
        exit (-1);
    }
}
