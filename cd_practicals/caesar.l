%{
#include <stdio.h>
#include <ctype.h>

int key, choice;
%}

%%
[A-Za-z]+ {
    int i;
    char c;

    for (i = 0; yytext[i] != '\0'; i++) {
        c = yytext[i];

        if (isalpha(c)) {

            /* Encryption */
            if (choice == 1) {
                if (isupper(c))
                    c = 'A' + (c - 'A' + key) % 26;
                else
                    c = 'a' + (c - 'a' + key) % 26;
            }

            /* Decryption */
            else if (choice == 2) {
                if (isupper(c))
                    c = 'A' + (c - 'A' - key + 26) % 26;
                else
                    c = 'a' + (c - 'a' - key + 26) % 26;
            }

            printf("%c", c);
        }
    }
}

[^A-Za-z]+ {
    printf("%s", yytext);
}

%%

int main()
{
    printf("Enter (1) to Encrypt or (2) to Decrypt: ");
    scanf("%d", &choice);

    printf("Enter shift key (k): ");
    scanf("%d", &key);

    printf("\nEnter the text:\n");

    /* Remove the newline left by scanf */
    getchar();

    yylex();

    printf("\n");

    return 0;
}

int yywrap()
{
    return 1;
}