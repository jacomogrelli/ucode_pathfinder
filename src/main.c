#include "pathfinder.h"

int main (int argc, char **argv) {
    char *file_to_str = NULL;
    char **arr_str = NULL;
    int islands_count = 0;

    pf_errorcheck_all(argv, argc);

    if (argc > 0)
    file_to_str = mx_file_to_str(argv[1]); //считываем файл
    arr_str = mx_strsplit(file_to_str, '\n'); //рабиваем на массив по строкам
    islands_count = file_to_str[0] - 48; //считываем колличество уникальных островов
    
}
