/*
This practical reads the input text, counts the frequency of each word and displays the words along with
their counts in the form of a histogram.
*/


%{
#include <stdio.h>
#include <string.h>

#define MAX 1000

char word[MAX][50];
int count[MAX];
int n = 0;
%}

%%
[A-Za-z]+ {
    int i, found = 0;

    /* Check whether the word already exists */
    for (i = 0; i < n; i++) {
        if (strcmp(word[i], yytext) == 0) {
            count[i]++;
            found = 1;
            break;
        }
    }

    /* If it is a new word, store it */
    if (!found && n < MAX) {
        strcpy(word[n], yytext);
        count[n] = 1;
        n++;
    }
}

[ \t\n]+   ;
.          ;
%%

int main()
{
    int i, j;

    /* Start lexical analysis */
    yylex();

    printf("\nWORD\t\tFREQUENCY\tHISTOGRAM\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-15s %5d\t\t", word[i], count[i]);

        /* Print histogram */
        for (j = 0; j < count[i]; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

int yywrap()
{
    return 1;
}
