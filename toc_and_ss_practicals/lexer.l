%{
#include<stdio.h>
%}

%%
[0-9]+              { printf("NUMBER : %s\n",yytext); }
[a-zA-Z]+           { printf("IDENTIFIER : %s\n",yytext); }
"+"|"-"|"*"|"/"|"=" { printf("OPERATOR : %s\n",yytext); }
";"                 { printf("DELIMITER : %s\n",yytext); }
[ \t\n]+            ;
.                   { printf("UNKNOWN : %s\n",yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter Input:\n");
    yylex();
    return 0;
}