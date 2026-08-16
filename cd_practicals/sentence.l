%{
#include <stdio.h>
#include <string.h>

int conjunction_found = 0;
%}

%%
(and|but|or|yet|so|for|nor) {
    conjunction_found = 1;
}

[A-Za-z]+       ;
[,.!?;:]        ;
[ \t\n]+        ;
.               ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a statement:\n");
    yylex();

    if(conjunction_found)
        printf("The statement is Compound.\n");
    else
        printf("The statement is Simple.\n");

    return 0;
}