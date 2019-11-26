#include "pathfinder.h"

static int pf_count_malloc(char *buf);

char ***pf_matrix_init(char **argv) {
    char *buf = mx_file_to_str(argv[1]);
    char ***result = (char ***)malloc(sizeof (char **) * pf_count_malloc(buf));
    int count = 0;
    
    for (int i = 0; buf; i++) {
        for (int i = 0, k = 0, delim = 0; *buf != '\n'; buf++) {
            count = mx_get_char_index(buf, '-');
            result[i][k] = mx_strndup(buf, (size_t)count);
            k++;
            buf = buf + count + 2;
            delim = count + 1;
            count = mx_get_char_index(buf, ',');
            result[i][k] = mx_strndup(buf, count - delim);
            k++;
            buf = buf + count + 2;
            delim = count + 1;
            count = mx_get_char_index(buf, '\n');
            result[i][k] = mx_strndup(buf, count - delim + 1);
            buf += 1;
        }
    }
    return result;
}

static int pf_count_malloc(char *buf) {
    int res = 0;
    
    res = mx_count_words(buf, '\n') * 3;
    return res;
}
