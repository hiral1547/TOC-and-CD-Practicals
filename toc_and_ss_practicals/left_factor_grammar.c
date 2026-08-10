#include <stdio.h>
#include <string.h>

// left factor the given grammar
int main()
{
    int n, i, j;

    char grammar[20][100];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    getchar();   // Clear newline from input buffer

    // Read all productions
    for(i = 0; i < n; i++)
    {
        printf("Enter Production %d: ", i + 1);
        fgets(grammar[i], sizeof(grammar[i]), stdin);

        // Remove newline character
        grammar[i][strcspn(grammar[i], "\n")] = '\0';
    }

    printf("\nOriginal Grammar:\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\n", grammar[i]);
    }

    printf("\nLeft Factored Grammar:\n");

    for(i = 0; i < n; i++)
    {
        char lhs;
        char p1[50] = "", p2[50] = "", prefix[50] = "";
        int k = 0, l = 0, pos = 3;

        lhs = grammar[i][0];

        // Check whether production has '|'
        if(strchr(grammar[i], '|') != NULL)
        {
            // First alternative
            while(grammar[i][pos] != '|' && grammar[i][pos] != '\0')
            {
                p1[k++] = grammar[i][pos++];
            }
            p1[k] = '\0';

            pos++; // Skip '|'

            // Second alternative
            while(grammar[i][pos] != '\0')
            {
                p2[l++] = grammar[i][pos++];
            }
            p2[l] = '\0';

            // Find common prefix
            int m = 0;
            while(p1[m] == p2[m] && p1[m] != '\0')
            {
                prefix[m] = p1[m];
                m++;
            }
            prefix[m] = '\0';

            if(strlen(prefix) > 0)
            {
                printf("%c -> %s%c'\n", lhs, prefix, lhs);
                printf("%c' -> %s | %s\n", lhs, p1 + m, p2 + m);
            }
            else
            {
                printf("%s\n", grammar[i]);
            }
        }
        else
        {
            // No left factoring needed
            printf("%s\n", grammar[i]);
        }
    }

    return 0;
}


/* 
S -> abC | abD
A -> xyB | xyC
B -> b
C -> c
D -> d
*/
