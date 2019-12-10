#include "pathfinder.h"

int main (int argc, char **argv) {
    char **mat = NULL;
    char **uniq_mat = NULL;
    int **adj_mat = NULL;
    int **rout_mat = NULL;
    int isl_count = 0;


    mat = mx_pf_errorcheck_all(argv, argc, &isl_count);
    uniq_mat = mx_pf_uniq_matrix(mat, &isl_count);
    adj_mat = mx_pf_adjmat(mat, uniq_mat, isl_count);
    rout_mat = mx_pf_pink_floyd(adj_mat, isl_count);
    mx_pf_output(uniq_mat, adj_mat, rout_mat);

    system ("leaks -q pathfinder");
}
