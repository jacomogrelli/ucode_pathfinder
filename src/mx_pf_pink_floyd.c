#include "pathfinder.h"

static int **pf_rout_mat_init(int c);

int **mx_pf_pink_floyd(int **adj_mat, int count) {
    int **rout_mat = pf_rout_mat_init(count);
    
    for (int k = 0; k < count; ++k) {
	    for (int y = 0; y < count; ++y) {
		    for (int x = 0; x < count; ++x) {
                if (adj_mat[y][x] > adj_mat[y][k] + adj_mat[k][x]) {
			        adj_mat[y][x] = adj_mat[y][k] + adj_mat[k][x];
                    rout_mat[y][x] = k;
                }
            }
        }
    }
    return rout_mat;
}

static int **pf_rout_mat_init(int c) {
    int **rout_mat = (int **)malloc(sizeof(int *) * c);

    for (int y = 0; y < c; y++) {
        rout_mat[y] = (int *)malloc(sizeof(int) * c);
        for (int x = 0; x < c; x++) {
            rout_mat[y][x] = x;
            // if (y == x)
            //     rout_mat[y][x] = 0;
        }
    }
    return rout_mat;
}
