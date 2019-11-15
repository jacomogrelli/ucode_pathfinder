#include "pathfinder.h"

static void pf_error_invalid_argc(void);
static void pf_error_invalid_name(char *argv);
static void pf_error_empty(char *agrv);
static void pf_error_invalid_1line(void);

void pf_errorcheck_all(char **argv, int argc) {
    char *file_to_str = NULL;
    char **arr_str = NULL;
    
    if (argc != 2) //проверка указан ли файл как аргумент
    pf_error_invalid_argc();
    file_to_str = mx_file_to_str(argv[1]);
    if (file_to_str == NULL) //проверка на пустой файл
    pf_error_invalid_name(argv[1]);
    if (file_to_str[0] == '\0') //проверка существует ли файл
    pf_error_empty(argv[1]);
    arr_str = mx_strsplit(file_to_str, '\n'); //разбиваем на массив строк
    while (arr_str[0]) {
        if(!mx_isdigit(*arr_str[0]))
        pf_error_invalid_1line();
        arr_str[0]++;
    }


}

static void pf_error_invalid_argc(void) {
    mx_printerr("usage: ./pathfinder [filename]\n");
    exit (1);
}

static void pf_error_invalid_name(char *argv) {
    mx_printerr("error: file ");
    mx_printerr(argv);
    mx_printerr(" doesn't exist\n");
    exit (1);
}

static void pf_error_empty(char *argv) {
    mx_printerr("error: file ");
    mx_printerr(argv);
    mx_printerr(" is empty\n");
    exit (1);
}

static void pf_error_invalid_1line(void) {
    mx_printerr("error: line 1 isn't valid\n");
    exit (1);
}