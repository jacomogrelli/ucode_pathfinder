#include "pathfinder.h"

static void pf_error_num();
static char **pf_temp_matrix(char **src);
static void pf_dupdel(char **buf, int *count);

char **mx_pf_uniq_matrix(char **matrix, int *isl_count) {
    char **temp = NULL;
    
    temp = pf_temp_matrix(matrix);
    pf_dupdel(temp, isl_count);
    return temp;
}

static void pf_error_num() {
    mx_printerr("error: invalid number of islands\n");
    exit (-1);
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

    while (buf[++len]);
    for (int i = 0; i < len; i++) {
        for (int k = i + 1; k < len; k++) {
            if (mx_strcmp(buf[i], buf[k]) == 0) {
                for (int j = k; j < len; j++) {
                    buf[j] = buf[j + 1];
                }
                len--;
                mx_strdel(&buf[len]);
            }
        }
    }
    if (len != *count)
        pf_error_num();
}
