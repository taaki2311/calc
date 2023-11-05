#include "hash.h"

#define HASHMAP_LENGTH 256

struct linkedlist *hashmap[HASHMAP_LENGTH];

static uint8_t hashCalc(const char *name)
{
    uint8_t hash = 0;
    uint8_t index = 0;
    while (name[index] != '\0')
    {
        hash ^= name[index];
        index++;
    }
    return hash;
}

void hashUpdate(struct variable *var)
{
    uint8_t hash = hashCalc(var->name);
    struct variable *home = linkedlistFind(hashmap[hash], var->name);
    home->type = var->type;
    home->value = var->value;
}

struct variable *hashGet(const char *name)
{
    uint8_t hash = hashCalc(name);
    return linkedlistFind(hashmap[hash], name);
}