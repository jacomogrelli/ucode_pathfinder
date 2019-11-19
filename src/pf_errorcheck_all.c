#include "pathfinder.h"

static void pf_error_invalid_argc(void);
static void pf_error_invalid_name(char *argv);
static void pf_error_empty(char *agrv);
static void pf_error_invalid_1line(void);
static void pf_error_invalid_lineval(int count);

void pf_errorcheck_all(char **argv, int argc) {
    char *file_to_str = NULL;
    int line_count = 1;
    
    if (argc != 2) //проверка указан ли файл как аргумент
    pf_error_invalid_argc();
    file_to_str = mx_file_to_str(argv[1]);
    if (file_to_str == NULL) //проверка существует ли файл
    pf_error_invalid_name(argv[1]);
    if (file_to_str[0] == '\0') //проверка на пустой файл
    pf_error_empty(argv[1]);
    while(*file_to_str != '\n') { //проверка первой строки
        if(!mx_isdigit(*file_to_str))
        pf_error_invalid_1line();
        file_to_str++;
    }
    file_to_str++;
    while(*file_to_str != '\0') {
        while(*file_to_str != '-' && *file_to_str) { //проверка первого города
            if(!mx_isalpha(*file_to_str))
            pf_error_invalid_lineval(line_count);
            file_to_str++;
        }
        file_to_str++;
        while(*file_to_str != ',' && *file_to_str) { //проверка второго города
            if(!mx_isalpha(*file_to_str))
            pf_error_invalid_lineval(line_count);
            file_to_str++;
        }
        file_to_str++;
        while(*file_to_str != '\n' && *file_to_str) { //проверка длинны моста
            if(!mx_isdigit(*file_to_str))            
            pf_error_invalid_lineval(line_count);
            file_to_str++;
        }
        line_count++;
        file_to_str++;
    }
    return;
}

static void pf_error_invalid_argc(void) {
    mx_printerr("usage: ./pathfinder [filename]\n");
    exit (-1);
}

static void pf_error_invalid_name(char *argv) {
    mx_printerr("error: file ");
    mx_printerr(argv);
    mx_printerr(" doesn't exist\n");
    exit (-1);
}

static void pf_error_empty(char *argv) {
    mx_printerr("error: file ");
    mx_printerr(argv);
    mx_printerr(" is empty\n");
    exit (-1);
}

static void pf_error_invalid_1line(void) {
    mx_printerr("error: line 1 isn't valid\n");
    exit (-1);
}

static void pf_error_invalid_lineval(int count) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(count + 1));
    mx_printerr(" isn't valid\n");
    exit (-1);
}
