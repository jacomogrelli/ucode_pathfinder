#include "pathfinder.h"

int main (int argc, char **argv) {
    char **matrix = NULL;
    char **uniq_matrix = NULL;
    char **rout_mat = NULL;
    int isl_count = 0;

    matrix = mx_pf_errorcheck_all(argv, argc, &isl_count);
    uniq_matrix = mx_pf_uniq_matrix(matrix, &isl_count);
}
