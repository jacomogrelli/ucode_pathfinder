#include "pathfinder.h"

int main (int argc, char **argv) {
    char **mat = NULL;
    char **uniq_mat = NULL;
    int **adj_mat = NULL;
    int isl_count = 0;

    mat = mx_pf_errorcheck_all(argv, argc, &isl_count);
    uniq_mat = mx_pf_uniq_matrix(mat, &isl_count);
    adj_mat = mx_pf_adjmat(mat, uniq_mat, isl_count);
        for (int y = 0, x = 0; y < isl_count; y++) {
        for(;adj_mat[y][x]; x++) {
            printf(" %d ", adj_mat[y][x]);
        }
        printf("%d\n", y);
    }

}
    // //печать матрицы интов
    // mx_print_strarr(uniq_mat, "\n");
    // mx_printstr("___________________\n");

    // for (int y = 0, x = 0; y < isl_count; y++) {
    //     for(;adj_mat[y][x]; x++) {
    //         printf(" %d ", adj_mat[y][x]);
    //     }
    //     printf("%d\n", y);
    // }
