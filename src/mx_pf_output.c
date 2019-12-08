#include "pathfinder.h"

static void pf_print(char **uniq_mat, int **adj_mat, int *stack);
static int *pf_stack_fill(int *res);

void mx_pf_output(char **uniq_mat, int **adj_mat, int **rout_mat) {
    int *stack = malloc(sizeof(int) * 10);
    int k;
    int a = 1;

    if (adj_mat[0][0] == 0)
    for (int i = 0; uniq_mat[i]; i++) {
        for (int j = i + 1; uniq_mat[j]; j++) {
            stack = pf_stack_fill(stack);
            stack[0] = j;
            k = rout_mat[i][j];
            if (k != j) {
                for (int b = j; k != b; a++) {
                    stack[a] = k;
                    b = k;
                    k = rout_mat[i][b];
                }
            }
            stack[a] = i;
            a = 1;
            pf_print(uniq_mat, adj_mat, stack);
            // exit (-1);
        }
    }
}

static void pf_print(char **uniq_mat, int **adj_mat, int *stack) {
    int len = 0;
            //     for (int b = 0; b < 10; b++) {
            //     printf("%d ", stack[b]);
            // }
            // printf("\n");

    while (stack[len + 1] != -2)
        len++;
    // printf("%d\n", len);
    mx_printstr("========================================\nPath: ");
    mx_printstr(uniq_mat[stack[len]]);
    mx_printstr(" -> ");
    mx_printstr(uniq_mat[stack[0]]);
    mx_printstr("\nRoute: ");
    for (int i = len; i > 0; i--) {
        mx_printstr(uniq_mat[stack[i]]);
        mx_printstr(" -> ");
    }
    mx_printstr(uniq_mat[stack[0]]);
    mx_printstr("\nDistance: ");
    if (len - 1 != 0) {
        for (int i = len - 1; i > 0; i--) {
            mx_printint(adj_mat[stack[len]][stack[i]]);
            mx_printstr(" + ");
        }
    }
}

static int *pf_stack_fill(int *res) {
    for (int i = 0; i < 10; i++) {
        res[i] = -2;
    }
    return res;
}

            // for (int b = 0; b < 10; b++) {
            //     printf("%d ", stack[b]);
            // }
            // printf("\n");
            // a = 1;
