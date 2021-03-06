#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "libmx.h"

//---ERROR PACK---
char **mx_pf_errorcheck_all(char **argv, int argc, int *isl_count);
void mx_pf_line_check(char *mat);

//---PARTH PACK---
char **mx_pf_uniq_matrix(char **matrix, int *isl_count);
char **mx_pf_matrix_init(char *argv, int *isl_count);
int **mx_pf_adjmat(char **mat, char **uniq_mat, int count);
int **mx_pf_pink_floyd(int **adj_mat, int count);
void mx_pf_output(char **uniq_mat, int **adj_mat, int **rout_mat);
void mx_pf_print(char **uniq_mat, int **adj_mat, int *stack);

#endif
