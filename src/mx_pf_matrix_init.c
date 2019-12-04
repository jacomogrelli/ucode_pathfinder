#include "pathfinder.h"

char **mx_pf_matrix_init(char *argv, int *isl_count) {
    int count = mx_count_words(argv, '\n');
    char **temp = malloc(sizeof (char *) * count + 1);
    char **temp2 = malloc(sizeof(char *) * ((count - 1) * 3 + 1));

    temp = mx_strsplit(argv, '\n');
    *isl_count = mx_atoi(temp[0]);
    for (int i = 1, k = 0; i < count; i++) {
        size_t c_min = mx_get_char_index(temp[i], '-');
        size_t c_koma = mx_get_char_index(temp[i], ',');
        size_t c_end = mx_get_char_index(temp[i], '\n');
        temp2[k] = mx_strndup(temp[i], c_min);
        temp2[k + 1] = mx_strndup(temp[i] + c_min + 1, c_koma - c_min - 1);
        temp2[k + 2] = mx_strndup(temp[i] + c_koma + 1, c_end - c_koma - 1);
        k += 3;
    }
    mx_del_strarr(&temp);
    temp2[(count - 1) * 3] = NULL;
    return temp2;
}
