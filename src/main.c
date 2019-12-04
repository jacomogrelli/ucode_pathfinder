#include "pathfinder.h"

int main (int argc, char **argv) {
    char **mat = NULL;
    char **uniq_mat = NULL;
    int **adj_mat = NULL;
    int isl_count = 0;

    mat = mx_pf_errorcheck_all(argv, argc, &isl_count);
    uniq_mat = mx_pf_uniq_matrix(mat, &isl_count);
    adj_mat = mx_pf_adjmat(mat, uniq_mat, isl_count);
        mx_print_strarr(uniq_mat, "\n");
    mx_printstr("___________________\n");
        for (int y = 0; y < isl_count; y++) {
        for(int x = 0; x < isl_count; x++) {
            printf(" %d ", adj_mat[y][x]);
        }
        printf("\n");
    }
    // mx_del_strarr(&mat);
    // mx_del_strarr(&uniq_mat);

    // system("leaks pathfinder");
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
