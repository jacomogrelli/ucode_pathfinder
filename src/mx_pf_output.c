#include "pathfinder.h"

static void pf_first_part(char *dep_point, char *des_point);
static void pf_last_part(char *des_point, int adj_mat);

void mx_pf_output(char **mat, char **uniq_mat, int **adj_mat, int **rout_mat)
{
    for (int i = 0; uniq_mat[i]; i++) {
        for (int j = i + 1; uniq_mat[j]; j++) {
            pf_first_part(uniq_mat[i], uniq_mat[j]);
            for (int k = rout_mat[i][j]; k != rout_mat[i][k];) {
                k = rout_mat[i][k];
            }
            pf_last_part(uniq_mat[j], adj_mat[i][j]);
        }
    }
}

static void pf_first_part(char *dep_point, char *des_point) {
    mx_printstr("========================================$\n");
    mx_printstr("Path: ");
    mx_printstr(dep_point);
    mx_printstr(" -> ");
    mx_printstr(des_point);
    mx_printstr("Route: ");
    mx_printstr(dep_point);
    mx_printstr(" -> ");
}

static void pf_last_part(char *des_point, int adj_mat) {
    mx_printstr(des_point);
    mx_printstr("Distance: ");
    mx_printint(adj_mat);
    mx_printstr("========================================$\n");
}