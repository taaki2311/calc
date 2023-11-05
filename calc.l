%{
#include "calc.h"
#include "y.tab.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *error);

void getText(void);
void getNumber(void);

%}

%%

[0-9_]*[A-Z][A-Z0-9_]+                  { getText(); return VARIABLE; }
[0-9]+                                  { getNumber(); return NUMBER; }
[ \t\n\r]+                              { ; }
.                                       { ECHO; yyerror("unexpected character"); }

%%

void getText(void) {
    yylval.string = malloc(yyleng);
    if (yylval.string == NULL) {
        yyerror("Failed to allocate memory");
    }
    yylval.string = strncpy(yylval.string, yytext, yyleng);
}

void getNumber(void) {
    yylval.number = strtol(yytext, NULL, 10);
}

int yywrap(void) { return 1; }