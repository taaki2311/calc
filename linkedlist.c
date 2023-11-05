#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

struct variable *linkedlistFind(struct linkedlist *list, const char *name) {
    struct linkedlist *prev = list;
    struct variable *var;
    struct linkedlist *node;

    while (list != NULL) {
        if (strcmp(list->var->name, name) == 0) {
            return list->var;
        }
        else {
            prev = list;
            list = list->next;
        }
    }

    var = malloc(sizeof(struct variable));
    var->name = name;
    var->type = LITERAL;
    var->value.number = 1;

    node = malloc(sizeof(struct linkedlist));
    node->var = var;
    prev->next = node;

    return var;
}