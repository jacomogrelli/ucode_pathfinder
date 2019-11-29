#include "pathfinder.h"

int main (int argc, char **argv) {
    char *file_to_str = NULL;
    // char *uniq_isl = NULL;
    char **matrix_buf = NULL;
    char **matrix_uniq = NULL;
    int islands_count = 0;

    pf_errorcheck_all(argv, argc); //проверяем все ошибки, кроме совпадения к-ва островов
    file_to_str = mx_file_to_str(argv[1]); //считываем файл
    matrix_buf = pf_matrix_init(file_to_str, &islands_count);
    
    matrix_uniq = pf_uniq_matrix(matrix_buf, &islands_count);
        // mx_print_strarr(matrix_buf, "\n");
    // for (int i = 0; matrix_buf[i] != NULL; i++) {
    //     printf("%s\n", matrix_buf[i]);
    // }
    // // file_to_str = mx_file_to_str(argv[1]); //считываем файл
    // uniq_isl = pf_uniq_matrix(file_to_str);
    // matrix = pf_matrix_init(argv);
    // for (int i = 0; i < 4; i++) {
    //     for (int k = 0; k < 3; k++) {
    //     printf("%s\n", matrix[i][k]);
    //     }
    // }
}
