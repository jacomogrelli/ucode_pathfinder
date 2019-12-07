#include "pathfinder.h"

int main (int argc, char **argv) {
    char **mat = NULL;
    char **uniq_mat = NULL;
    int **adj_mat = NULL;
    int **rout_mat = NULL;
    int isl_count = 0;


    mat = mx_pf_errorcheck_all(argv, argc, &isl_count);
    uniq_mat = mx_pf_uniq_matrix(mat, &isl_count);
    // mx_print_strarr(uniq_mat, "\n");
    // mx_printstr("uniq_mat____________\n");
    adj_mat = mx_pf_adjmat(mat, uniq_mat, isl_count);
    // for (int y = 0; y < isl_count; y++) {
    //     for(int x = 0; x < isl_count; x++) {
    //         printf(" %d ", adj_mat[y][x]);
    //     }
    //     printf("\n");
    // }
    // mx_printstr("adj_mat_before____________\n");
    rout_mat = mx_pf_pink_floyd(adj_mat, isl_count);
    mx_pf_output(uniq_mat, adj_mat, rout_mat);
    // for (int y = 0; y < isl_count; y++) {
    //     for(int x = 0; x < isl_count; x++) {
    //         printf(" %d ", adj_mat[y][x]);
    //     }
    //     printf("\n");
    // }
    // mx_printstr("adj_mat_after____________\n");
    // for (int y = 0; y < isl_count; y++) {
    //     for(int x = 0; x < isl_count; x++) {
    //         printf(" %d ", rout_mat[y][x]);
    //     }
    //     printf("\n");
    // }
    // mx_printstr("route_mat____________\n");




    // mx_del_strarr(&mat);
    // mx_del_strarr(&uniq_mat);
    system ("leaks -q pathfinder");

}
    // //печать матрицы интов
    //    mx_print_strarr(uniq_mat, "\n");
    // mx_printstr("___________________\n");
    //     for (int y = 0; y < isl_count; y++) {
    //     for(int x = 0; x < isl_count; x++) {
    //         printf(" %d ", adj_mat[y][x]);
    //     }
    //     printf("\n");
    // }
