#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 50
#define MAX_LEN 100

typedef struct
{
    char lhs;
    char rhs[MAX_PRODUCTIONS][MAX_LEN];
    int count;
} Production;

int main()
{
    Production grammar[MAX_PRODUCTIONS];
    Production newProductions[MAX_PRODUCTIONS];

    int n;
    int newCount = 0;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("\nEnter productions (example: S->Sa|b)\n");

    /* Read grammar */
    for (int i = 0; i < n; i++)
    {
        char input[MAX_LEN];

        printf("Production %d: ", i + 1);
        scanf("%s", input);

        /* Get LHS */
        grammar[i].lhs = input[0];
        grammar[i].count = 0;

        /* Find -> */
        char *rhs = strstr(input, "->");

        if (rhs == NULL)
        {
            printf("Invalid production!\n");
            return 1;
        }

        rhs += 2;

        /* Split RHS using | */
        char *token = strtok(rhs, "|");

        while (token != NULL)
        {
            strcpy(grammar[i].rhs[grammar[i].count], token);
            grammar[i].count++;

            token = strtok(NULL, "|");
        }
    }

    /*
     * Remove immediate left recursion
     */
    for (int i = 0; i < n; i++)
    {
        char recursive[MAX_PRODUCTIONS][MAX_LEN];
        char nonRecursive[MAX_PRODUCTIONS][MAX_LEN];

        int recursiveCount = 0;
        int nonRecursiveCount = 0;

        char A = grammar[i].lhs;

        /*
         * Separate:
         *
         * A -> Aα  (recursive)
         * A -> β   (non-recursive)
         */
        for (int j = 0; j < grammar[i].count; j++)
        {
            if (grammar[i].rhs[j][0] == A)
            {
                strcpy(recursive[recursiveCount],
                       grammar[i].rhs[j] + 1);

                recursiveCount++;
            }
            else
            {
                strcpy(nonRecursive[nonRecursiveCount],
                       grammar[i].rhs[j]);

                nonRecursiveCount++;
            }
        }

        /*
         * If no left recursion, leave production unchanged.
         */
        if (recursiveCount == 0)
            continue;

        /*
         * Create a new non-terminal A'
         */
        char newA = A + 1;

        /*
         * Make sure the new non-terminal is not
         * already used as an LHS.
         */
        int used;

        do
        {
            used = 0;

            for (int k = 0; k < n; k++)
            {
                if (grammar[k].lhs == newA)
                {
                    used = 1;
                    newA++;
                    break;
                }
            }

            for (int k = 0; k < newCount; k++)
            {
                if (newProductions[k].lhs == newA)
                {
                    used = 1;
                    newA++;
                    break;
                }
            }

        } while (used);

        /*
         * A -> βA'
         */
        grammar[i].count = 0;

        for (int j = 0; j < nonRecursiveCount; j++)
        {
            char temp[MAX_LEN];

            strcpy(temp, nonRecursive[j]);

            int len = strlen(temp);

            temp[len] = newA;
            temp[len + 1] = '\0';

            strcpy(grammar[i].rhs[grammar[i].count],
                   temp);

            grammar[i].count++;
        }

        /*
         * A' -> αA' | epsilon
         */
        Production newP;

        newP.lhs = newA;
        newP.count = 0;

        for (int j = 0; j < recursiveCount; j++)
        {
            char temp[MAX_LEN];

            strcpy(temp, recursive[j]);

            int len = strlen(temp);

            temp[len] = newA;
            temp[len + 1] = '\0';

            strcpy(newP.rhs[newP.count], temp);

            newP.count++;
        }

        strcpy(newP.rhs[newP.count], "epsilon");
        newP.count++;

        newProductions[newCount] = newP;
        newCount++;
    }

    /*
     * Display final grammar
     */
    printf("\n----------------------------------\n");
    printf("Grammar after Removing Left Recursion\n");
    printf("----------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%c -> ", grammar[i].lhs);

        for (int j = 0; j < grammar[i].count; j++)
        {
            printf("%s", grammar[i].rhs[j]);

            if (j != grammar[i].count - 1)
                printf(" | ");
        }

        printf("\n");
    }

    /* Print newly generated productions */
    for (int i = 0; i < newCount; i++)
    {
        printf("%c -> ", newProductions[i].lhs);

        for (int j = 0; j < newProductions[i].count; j++)
        {
            printf("%s", newProductions[i].rhs[j]);

            if (j != newProductions[i].count - 1)
                printf(" | ");
        }

        printf("\n");
    }

    return 0;
}
