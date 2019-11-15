#include "pathfinder.h"

static void pf_error_invalid_argc(void);
static void pf_error_empty(char *agrv);

void pf_errorcheck_all(char **argv, int argc) {
    char *file_to_str = NULL;
    // char **arr_str = NULL;
    
    if (argc != 2) //проверка указан ли файл как аргумент
    pf_error_invalid_argc();
    file_to_str = mx_file_to_str(argv[1]);
    if (file_to_str == NULL) //проверка на пустой файл
    pf_error_empty(argv[1]);
}

static void pf_error_invalid_argc(void) {
    mx_printerr("usage: ./pathfinder [filename]\n");
    exit (1);
}

static void pf_error_empty(char *argv) {
    mx_printerr("error: file ");
    mx_printerr(argv);
    mx_printerr(" is empty\n");
    exit (1);
}
