#ifndef VARIABLE_H
#define VARIABLE_H

enum operation
{
    NONE = 0,
    ADD,
    SUBTRACT
};

struct reference;
struct variable
{
    const char *name;

    enum
    {
        LITERAL,
        REFERENCE
    } type;

    union
    {
        long number;
        struct reference *ref;
    } value;
};

struct reference
{
    struct variable *operand;
    enum operation operation;
    struct reference *next;
};

#endif /* VARIABLE_H */