#include "pathfinder.h"

static int **pf_adjmat0(int c); //заполняем матрицу нулями или чем-то

int **mx_pf_adjmat(char **mat, char **uniq_mat, int count) {
    int **adj_mat = pf_adjmat0(count); //заполняем матрицу нулями или чем-то
    int x = 0;
    int y = 0;

    for (int i = 0; mat[i] != NULL; i += 3) {
        for (int k = 0; uniq_mat[k]; k++) { //находим в матрице уникальных Х
            if (mx_strcmp(mat[i], uniq_mat[k]) == 0)
                x = k;
        }
        for (int k = 0; uniq_mat[k]; k++) { //находим в матрице уникальных У
            if (mx_strcmp(mat[i + 1], uniq_mat[k]) == 0)
                y = k;
        }
        adj_mat[y][x] = mx_atoi(mat[i + 2]); //записываем расстояние
        adj_mat[x][y] = adj_mat[y][x];       //и зеркально, т.к. граф ненапр
    }
    return adj_mat;
}

static int **pf_adjmat0(int c) {
    int **buf = (int **)malloc(sizeof(int *) * c);

    for (int y = 0; y < c; y++) {
        buf[y] = (int *)malloc(sizeof(int) * c);
        for (int x = 0; x < c; x++) {
            buf[y][x] = 2147483647;
            if (x == y) //записываем 0 что бы исключить круги
                buf[y][x] = 0;
        }
    }
    return buf;
}
