/* 
Comments Lex Program:
    Extracts single-line (//) and multi-line (/* */) comments from a C source file and displays them separately.
    It also counts the number of each type of comment.
*/

%{
#include <stdio.h>
#include <string.h>

int scount = 0;
int mcount = 0;
%}

%%
"//"[^\n]* {
    printf("%s\n", yytext);
    scount++;
}

"/"\*([^*]|\*+[^*/])*\*+"/" {
    printf("%s\n", yytext);
    mcount++;
}

[\t\r\n]+   ;

.           ;

%%

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <input.c>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");

    if (!yyin) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    printf("\n----- Extracted Comments -----\n");

    yylex();

    fclose(yyin);

    printf("\nTotal Single Line Comments : %d\n", scount);
    printf("Total Multi Line Comments  : %d\n", mcount);

    return 0;
}

int yywrap()
{
    return 1;
}
