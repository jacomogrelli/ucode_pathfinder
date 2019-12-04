#include "pathfinder.h"

static void pf_error_invalid_lineval(int line);
static char *pf_skip_1line(char *mat);
static char *pf_1word(char *mat, int line);
static char *pf_2word(char *mat, int line);
static char *pf_3word(char *mat, int line);

void mx_pf_line_check(char *mat) {
    int line = 2;

    mat = pf_skip_1line(mat);
    while (*mat) {
        mat = pf_1word(mat, line);
        mat = pf_2word(mat, line);
        mat = pf_3word(mat, line);
        line++;
        if (*mat == '\0')
            break;
        mat++;
    }
}

static void pf_error_invalid_lineval(int line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(line));
    mx_printerr(" is not valid\n");
    exit (-1);
}

static char *pf_skip_1line(char *mat) {
    while (*mat != '\n')
        mat++;
    return mat + 1;
}

static char *pf_1word(char *mat, int line) {
    if (*mat == '-') //\0 отсекает последнюю пустую строку
        pf_error_invalid_lineval(line);
    while (*mat != '-' && *mat) { //проверка первого города
        if (!mx_isalpha(*mat))
        pf_error_invalid_lineval(line);
        mat++;
        }
    return mat + 1;
}

static char *pf_2word(char *mat, int line) {
    if (*mat == ',')
        pf_error_invalid_lineval(line);
    while (*mat != ',' && *mat) { //проверка второго города
        if (!mx_isalpha(*mat))
            pf_error_invalid_lineval(line);
            mat++;
        }
    return mat + 1;
}

static char *pf_3word(char *mat, int line) {
    if (*mat == '\n')
        pf_error_invalid_lineval(line);
    while (*mat != '\n' && *mat) { //проверка длинны моста
        if (!mx_isdigit(*mat))            
        pf_error_invalid_lineval(line);
        mat++;
    }
    return mat;
}
