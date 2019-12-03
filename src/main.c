#include "pathfinder.h"

int main (int argc, char **argv) {
    char **mat = NULL;
    char **uniq_mat = NULL;
    char **adj_mat = NULL;
    int isl_count = 0;

    mat = mx_pf_errorcheck_all(argv, argc, &isl_count);
    uniq_mat = mx_pf_uniq_matrix(mat, &isl_count);
    adj_mat = 
}
