#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "variable.h"

struct linkedlist {
    struct variable *var;
    struct linkedlist *next;
    struct linkedlist *top;
};

struct variable *linkedlistFind(struct linkedlist *list, const char *name);

#endif /* LINKEDLIST_H */