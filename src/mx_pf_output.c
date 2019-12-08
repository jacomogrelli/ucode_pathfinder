#include "pathfinder.h"

static int *pf_stack_fill(int *res);

void mx_pf_output(char **uniq_mat, int **adj_mat, int **rout_mat) {
    int *stack = malloc(sizeof(int) * 10);
    
    int a = 1;

    if (adj_mat[0][0] == 0)
    for (int i = 0; uniq_mat[i]; i++) {
        for (int j = i + 1; uniq_mat[j]; j++) {
            stack = pf_stack_fill(stack);
            stack[0] = j;
            for (int k = rout_mat[i][j]; k != rout_mat[i][k];) {
                stack[a] = rout_mat[i][k];
                a++;
            }
            stack[a] = i;
            a = 1;
        }

    for (int b = 0; b < 10; b++) {
        printf("%d ", stack[b]);
    }
    printf("\n");
    }
}

static int *pf_stack_fill(int *res) {
    for (int i = 0; i < 10; i++) {
        res[i] = -2;
    }
    return res;
}
