#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *node;

    if (!data)
        return;
    if ((*list) == NULL) {
        *list = mx_create_node(data);
        return;
    }
    node = mx_create_node(data);
    node->next = *list;
    *list = node;
}
