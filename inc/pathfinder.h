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
bool mx_isalpha(int c);

#endif
