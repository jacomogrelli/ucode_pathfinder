#include "pathfinder.h"

static int *pf_stack_fill(int *res);
static void pf_ebaniy_auditor(int *stack, int i, int *a);

void mx_pf_output(char **uniq_mat, int **adj_mat, int **rout_mat)
{
    int *stack = malloc(sizeof(int) * 10);
    int k;
    int a = 1;

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
            pf_ebaniy_auditor(stack, i, &a);
            mx_pf_print(uniq_mat, adj_mat, stack);
        }
    }
    free(stack);
}

static int *pf_stack_fill(int *res) {
    for (int i = 0; i < 10; i++) {
        res[i] = -2;
    }
    return res;
}

static void pf_ebaniy_auditor(int *stack, int i, int *a) {
    stack[*a] = i;
    *a = 1;
}
