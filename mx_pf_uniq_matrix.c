#include "pathfinder.h"

static void pf_error_num(int i, int isl);
static char **pf_temp_matrix(char **src);
static void pf_dupdel(char **buf, int *count);

char **mx_pf_uniq_matrix(char **matrix, int *isl_count) {
    char **temp = NULL;
    if (*isl_count > 0)

    temp = pf_temp_matrix(matrix);
    pf_dupdel(temp, isl_count);
    mx_print_strarr(temp, "\n");


    if (temp[0] == NULL)
    pf_error_num(4, 5);
    return temp;
}

static void pf_error_num(int i, int isl) {
    if (i == isl) {
        mx_printerr("error: invalid number of islands\n");
        exit (-1);
    }
}

static char **pf_temp_matrix(char **src) {
    char **res = NULL;
    int mal_size = 0;

    while (src[mal_size])
        mal_size++;
    mal_size = mal_size / 3 * 2;
    res = (char **)malloc(sizeof(char *) * mal_size + 1);
    for (int i = 0, k = 0; k < mal_size; i += 3, k += 2) {
        res[k] = mx_strdup(src[i]);
        res[k + 1] = mx_strdup(src[i + 1]);
    }
    res[mal_size] = NULL;
    return res;
}

static void pf_dupdel(char **buf, int *count) {
    int len = 0;

    mx_print_strarr(buf, "\n");
    printf("______\n");
    while (buf[++len]);
    for (int i = 0; i < len; i++) {
        for (int k = 1; k < len; k++) {
            if (mx_strcmp(buf[i], buf[k]) == 0) {
                for (int j = k; k < len; k++) {
                    buf[k] = buf[k + 1];
                }
                len--;
                // i = 0;
                // k = 1;
            }
        }
    }
    buf[len] = NULL;
    mx_print_strarr(buf, "\n");
    if (len != *count)
        pf_error_num(1, 1);
}

    // char **res = malloc(sizeof(char *) * *isl_count);
    // int i = 1;

    // res[0] = mx_strdup(matrix[0]);
    // res[1] = NULL;
    // for (int k = 1; matrix[k] != NULL; k++) {
    //     pf_error_num(i, *isl_count);
    //     for (int j = 0; res[j] || mx_strcmp(res[j], matrix[k]) != 0; j++) {
    //         if (res[j + 1] == NULL) {
    //             res[i] = mx_strdup(matrix[k]);
    //             res[i + 1] = NULL;
    //             printf("%s\n", res[i]);
    //             i++;
    //         }
    //     }
    //     if (matrix[k + 1] == NULL)
    //         break;
    // }
    // return res;
