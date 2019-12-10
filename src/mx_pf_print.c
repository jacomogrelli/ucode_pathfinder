#include "pathfinder.h"

void pf_print(char **uniq_mat, int **adj_mat, int *stack) {
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
