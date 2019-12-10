#include "pathfinder.h"

static void pf_print_path(char **uniq_mat, int *stack, int len);
static void pf_print_route(char **uniq_mat, int *stack, int len);
static void pf_print_dist(int **adj_mat, char **uniq_mat, int *stack, int len);

void mx_pf_print(char **uniq_mat, int **adj_mat, int *stack)
{
    int len = 0;

    while (stack[len] != -2)
        len++;
    pf_print_path(uniq_mat, stack, len);
    pf_print_route(uniq_mat, stack, len);
    pf_print_dist(adj_mat, uniq_mat, stack, len);
}

static void pf_print_path(char **uniq_mat, int *stack, int len) {
    mx_printstr("========================================\nPath: ");
    mx_printstr(uniq_mat[stack[len - 1]]);
    mx_printstr(" -> ");
    mx_printstr(uniq_mat[stack[0]]);
}

static void pf_print_route(char **uniq_mat, int *stack, int len) {
    mx_printstr("\nRoute: ");
    for (int i = len - 1; i > 0; i--) {
        mx_printstr(uniq_mat[stack[i]]);
        mx_printstr(" -> ");
    }
    mx_printstr(uniq_mat[stack[0]]);
}

static void pf_print_dist(int **adj_mat, char **uniq_mat, int *stack, int len)
{
    mx_printstr("\nDistance: ");
    if (len - 2 != 0) {
        for (int i = len - 1; i > 0; i--) {
            mx_printint(adj_mat[stack[i]][stack[i - 1]]);
            if (i - 1 != 0)
                mx_printstr(" + ");
            else {
                mx_printstr(" = ");
                mx_printint(adj_mat[stack[len - 1]][stack[0]]);
            }
        }
    }
    else {
        mx_printint(adj_mat[stack[len - 1]][stack[0]]);
    }
    mx_printstr("\n========================================\n");
}
