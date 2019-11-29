#include "pathfinder.h"

char **pf_uniq_matrix(char **matrix, int *isl_count) {
    

    // int i = mx_atoi(matrix[2]);
    if (*isl_count > 0)
    printf("%d\n", );
    return matrix;
}

// char **buf = NULL;
//     char **res = NULL;
//     int count = 1;
//     int k = 2;
//     if (*isl_count > 0)

//     while (matrix[count] != NULL) {
//         count++;
//     }
//         // mx_print_strarr(matrix, "\n");
//         // mx_printint(count);
//     buf = (char **)malloc(sizeof(char *) * count);
//     for (int i = 0; i < count; i++) {
//         buf[i] = mx_strdup(matrix[i]);
//     }
//     buf[count] = NULL;
//     for (int i = 0; buf[i]; i++) {
//         printf("%s\n", buf[i]);
//     }

//     for (; buf[k] != NULL; k += 2) {
//         for (int i = k; buf[i] != NULL; i++) {
//             buf[i] = buf[i + 1];
//             count = i;
//         }
//     }
//     k = mx_bubble_sort(buf, count);
//     for (int i = 0; buf[i + 1] != NULL; i++) {
//         for (int j = i + 1; buf[j] != NULL; j++) {
//             if (mx_strcmp(buf[i], buf[j]) == 0) {
//                 buf[i] = "del";
//                 i++;
//                 count--;
//             }
//         }
//     }
//     // mx_printint(count);
//     // if (*isl_count != count) {
//     //     mx_printerr("error: invalid number of islands\n");
//     //     exit (-1);
//     // }
//     res = malloc(sizeof(char *) * count);
//     for (int i = 0, j = 0; buf[j] != NULL; j++) {
//         if (mx_strcmp(buf[j], "del") != 0) {
//             res[i] = mx_strdup(buf[j]);
//             i++;
//         }
//     }
//     res[count] = NULL;
//     // mx_print_strarr(res, "\n");
//     // mx_printstr("-------------");
//     // mx_print_strarr(matrix, "\n");
//     // mx_del_strarr(&buf);
//     return res;
