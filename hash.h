#ifndef HASH_H
#define HASH_H

#include "linkedlist.h"
#include <stdint.h>

void hashUpdate(struct variable *var);
struct variable *hashGet(const char *name);

#endif /* HASH_H */
