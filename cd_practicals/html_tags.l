%{
#include <stdio.h>
%}

%%
"<"[^>]+">" {
    printf("%s\n", yytext);
}

.|\n ;
%%

int yywrap()
{
    return 1;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s filename.html\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");

    if(yyin == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("HTML Tags:\n");
    yylex();

    fclose(yyin);
    return 0;
}