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
#include "../libmx/inc/libmx.h"

//---ERROR PACK---
void pf_errorcheck_all(char **argv, int argc);

//---PARTH PACK---
char **pf_uniq_matrix(char **str);
char **pf_matrix_init(char *argv, int *isl_count);

#endif