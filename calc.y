%{
#include "calc.h"
#include <stdio.h>

int yylex(void);
void yyerror(const char *error);

//int yydebug = 1;

%}

%union {
    char *string;
    long number;
    enum operation operation;
    struct variable variable;
    struct reference reference;
}
%start statements

%type <variable> variable

%token EQUALS
%token <number> NUMBER
%token <string> VARIABLE
%token <operation> OPERATION

%%

statements  : statement
            | statements statement
            ;

statement   : VARIABLE EQUALS expression

expression  : variable
            | expression OPERATION variable
            ;

variable    : NUMBER    { $$.type = LITERAL; $$.value.number = $1; }
            | VARIABLE  { $$.type = REFERENCE; $$.value.ref = $1; }
            ;

%%

int main(void) {
    return yyparse();
}

void yyerror(const char *error) {
    fprintf(stderr, "%s\n", error);
}