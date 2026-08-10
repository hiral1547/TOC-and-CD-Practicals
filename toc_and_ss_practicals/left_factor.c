#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char lhs;
    char productions[10][50];
    int n = 0;

    printf("Enter grammar production: ");
    scanf("%s", input);

    /* Get left-hand side */
    lhs = input[0];

    /* Skip -> */
    char *rhs = strstr(input, "->");

    if (rhs == NULL)
    {
        printf("Invalid grammar format!\n");
        return 1;
    }

    rhs += 2;

    /* Split productions using | */
    char *token = strtok(rhs, "|");

    while (token != NULL)
    {
        strcpy(productions[n], token);
        n++;
        token = strtok(NULL, "|");
    }

    /* Find common prefix among productions */
    int prefixLength = 0;

    if (n >= 2)
    {
        while (1)
        {
            char ch = productions[0][prefixLength];

            if (ch == '\0')
                break;

            int same = 1;

            for (int i = 1; i < n; i++)
            {
                if (productions[i][prefixLength] != ch)
                {
                    same = 0;
                    break;
                }
            }

            if (!same)
                break;

            prefixLength++;
        }
    }

    printf("\nLeft Factored Grammar:\n");

    /* If there is no common prefix */
    if (prefixLength == 0)
    {
        printf("%c->", lhs);

        for (int i = 0; i < n; i++)
        {
            printf("%s", productions[i]);

            if (i != n - 1)
                printf("|");
        }

        printf("\n");
        return 0;
    }

    /* Print original non-terminal with common prefix */
    printf("%c->", lhs);

    for (int i = 0; i < prefixLength; i++)
        printf("%c", productions[0][i]);

    printf("%c'\n", lhs);

    /* Print new non-terminal */
    printf("%c'->", lhs);

    for (int i = 0; i < n; i++)
    {
        if (productions[i][prefixLength] == '\0')
        {
            /* Epsilon production */
            printf("epsilon");
        }
        else
        {
            printf("%s", productions[i] + prefixLength);
        }

        if (i != n - 1)
            printf("|");
    }

    printf("\n");

    return 0;
}
