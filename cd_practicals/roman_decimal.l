%{
#include <stdio.h>
#include <string.h>

int value(char c)
{
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToDecimal(char str[])
{
    int i, sum = 0;

    for(i = 0; str[i]; i++)
    {
        if(value(str[i]) < value(str[i+1]))
            sum -= value(str[i]);
        else
            sum += value(str[i]);
    }
    return sum;
}
%}

%%
[A-Z]+ {
    printf("Decimal = %d\n", romanToDecimal(yytext));
}
\n ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter Roman Number: ");
    yylex();
    return 0;
}