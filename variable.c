#include "hash.h"
#include <assert.h>
#include <stdio.h>

long solve(struct variable *var);

int main()
{
    struct variable a, b, c, d;
    struct reference c_ref, c_ref2, d_ref, d_ref2;

    a.name = "Apple";
    a.type = LITERAL;
    a.value.number = 23;
    hashUpdate(&a);

    b.name = "Banana";
    b.type = LITERAL;
    b.value.number = 11;
    hashUpdate(&b);

    c.name = "Cactus";
    c.type = REFERENCE;
    c.value.ref = &c_ref;
    c_ref.operand = hashGet(a.name);
    c_ref.next = &c_ref2,
    c_ref.operation = ADD;
    c_ref2.operand = hashGet(b.name);
    c_ref2.operation = NONE;
    c_ref2.next = NULL;
    hashUpdate(&c);

    d.name = "Daisy";
    d.type = REFERENCE;
    d.value.ref = &d_ref;
    d_ref.operand = hashGet(a.name);
    d_ref.operation = ADD;
    d_ref.next = &d_ref2;
    d_ref2.operand = hashGet(c.name);
    d_ref2.operation = NONE;
    d_ref2.next = NULL;
    hashUpdate(&d);

    printf("a = %ld, b = %ld, c = %ld, d = %ld\n",
           solve(hashGet(a.name)), solve(hashGet(b.name)), solve(hashGet(c.name)), solve(hashGet(d.name)));

    a.value.number = 47;

    printf("a = %ld, b = %ld, c = %ld, d = %ld\n",
           solve(hashGet(a.name)), solve(hashGet(b.name)), solve(hashGet(c.name)), solve(hashGet(d.name)));

    return 0;
}

static long dereference(struct reference *ref)
{
    long operand = solve(ref->operand);
    switch (ref->operation)
    {
    case NONE:
        return operand;
    case ADD:
        return operand + dereference(ref->next);
    case SUBTRACT:
        return operand - dereference(ref->next);
    }
    assert(0);
    return 0;
}

long solve(struct variable *var)
{
    switch (var->type)
    {
    case LITERAL:
        return var->value.number;
    case REFERENCE:
        return dereference(var->value.ref);
    }
    assert(0);
    return 0;
}