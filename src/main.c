#include "pathfinder.h"

static void pf_cl(char **mat, char **uniq_mat, int **adj_mat, int **rout_mat);

int main (int argc, char **argv) {
    char **mat = NULL;
    char **uniq_mat = NULL;
    int **adj_mat = NULL;
    int **rout_mat = NULL;
    int isl_count = 0;

    mat = mx_pf_errorcheck_all(argv, argc, &isl_count);
    // system("leaks pathfinder");
    uniq_mat = mx_pf_uniq_matrix(mat, &isl_count);
    adj_mat = mx_pf_adjmat(mat, uniq_mat, isl_count);
    // for (int i = 0; i < isl_count; i++) {
    //     for (int j = 0; j < isl_count; j++) {
    //         printf(" %d ", adj_mat[i][j]);
    //     }
    //     printf("\n");
    // }
    rout_mat = mx_pf_pink_floyd(adj_mat, isl_count);
    mx_pf_output(uniq_mat, adj_mat, rout_mat);
    pf_cl(mat, uniq_mat, adj_mat, rout_mat);
}

static void pf_cl(char **mat, char **uniq_mat, int **adj_mat, int **rout_mat) {
    int count = 0;

    while (uniq_mat[count])
        count++;
    mx_del_strarr(&mat);
    mx_del_strarr(&uniq_mat);
    for (int i = 0; i < count; i++) {
        free(adj_mat[i]);
    }
    free(adj_mat);
    for (int i = 0; i < count; i++) {
        free(rout_mat[i]);
    }
    free(rout_mat);
}
