#include "pathfinder.h"

char **pf_uniq_matrix(char **matrix, int *isl_count) {
    char **result = mx_bubble_sort(matrix, 12);
    if (*isl_count >= 0)
    mx_print_strarr(result, "__");
    return result;
}
