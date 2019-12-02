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
#include "libmx/inc/libmx.h"

//---ERROR PACK---
char **mx_pf_errorcheck_all(char **argv, int argc, int *isl_count);
void mx_pf_line_check(char *mat);

//---PARTH PACK---
char **mx_pf_uniq_matrix(char **matrix, int *isl_count);
char **mx_pf_matrix_init(char *argv, int *isl_count);

#endif
