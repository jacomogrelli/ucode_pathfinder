#include "pathfinder.h"

int main (int argc, char **argv) {
    char *file_to_str = NULL;
    // char *uniq_isl = NULL;
    // char ***matrix = NULL;
    // int islands_count = 0;

    pf_errorcheck_all(argv, argc);
    
    file_to_str = mx_file_to_str(argv[1]); //считываем файл
    // uniq_isl = pf_uniq_matrix(file_to_str);
    // matrix = pf_matrix_init(argv);
    // for (int i = 0; i < 4; i++) {
    //     for (int k = 0; k < 3; k++) {
    //     printf("%s\n", matrix[i][k]);
    //     }
    // }
}
