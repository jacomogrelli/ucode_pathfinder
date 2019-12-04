#include "pathfinder.h"

static void pf_error_invalid_1line(char *str);
static void pf_error_invalid_argc(int i);
static char *pf_error_inv_name_or_empty(char *str);

char **mx_pf_errorcheck_all(char **argv, int argc, int *isl_count) {
    char *str = NULL;
    char **matrix = NULL;
    
    pf_error_invalid_argc(argc); //проверка количества аргументов
    str = pf_error_inv_name_or_empty(argv[1]); //проверка файла и на пустой
    pf_error_invalid_1line(str); //проверка 1 строки
    matrix = mx_pf_matrix_init(str, isl_count);
    mx_pf_line_check(str);
    mx_strdel(&str);
    return matrix;
}

static void pf_error_invalid_argc(int i) {
    if (i != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit (-1);
    }
    return;
}

static void pf_error_invalid_1line(char *str) {
    for (int i = 0; str[i] != '\n'; i++) {
        if(!mx_isdigit(str[i])) {
            mx_printerr("error: line 1 is not valid\n");
            exit (-1);
        }
    }
    return;
}

static char *pf_error_inv_name_or_empty(char *str) {
    char *res = mx_file_to_str(str);

    if (res == NULL) {
        mx_printerr("error: file ");
        mx_printerr(str);
        mx_printerr(" does not exist\n");
        exit (-1);
    }
    if (*res == '\0') {
        mx_printerr("error: file ");
        mx_printerr(str);
        mx_printerr(" is empty\n");
        exit (-1);
    }
    if (*res == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        exit (-1);
    }
    return res;
}
