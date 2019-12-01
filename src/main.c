#include "pathfinder.h"

int main (int argc, char **argv) {
    // char *file_to_str = NULL;
    // char *uniq_isl = NULL;
    char **matrix = NULL;
    // char **matrix_uniq = NULL;
    int isl_count = 0;

    matrix = mx_pf_errorcheck_all(argv, argc, &isl_count);
    // mx_print_strarr(matrix, "\n");
    // mx_printint(isl_count);
    // mx_del_strarr(&matrix);
    // file_to_str = mx_file_to_str(argv[1]); //считываем файл
    // matrix_buf = pf_matrix_init(file_to_str, &isl_count);
    
    // matrix_uniq = pf_uniq_matrix(matrix_buf, &isl_count);
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
