#include "pathfinder.h"

int main (int argc, char **argv) {
    char *file_to_str = NULL;
    char *uniq_isl = NULL;
    int islands_count = 0;
    if (argc > 0)
    pf_errorcheck_all(argv, argc);
    
    file_to_str = mx_file_to_str(argv[1]); //считываем файл
    // printf("filie");
    uniq_isl = pf_uniq_matrix(file_to_str);
    islands_count = file_to_str[0] - 48; //считываем колличество уникальных островов
}
