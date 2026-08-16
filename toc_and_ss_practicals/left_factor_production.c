#include <stdio.h>
#include <string.h>

// left factor the given 2 productions
int main()
{
    char p1[30], p2[30];
    char prefix[30];
    int i = 0;

    printf("Enter First Production (without LHS): ");
    scanf("%s", p1);

    printf("Enter Second Production (without LHS): ");
    scanf("%s", p2);

    // Find common prefix
    while (p1[i] == p2[i] && p1[i] != '\0')
    {
        prefix[i] = p1[i];
        i++;
    }
    prefix[i] = '\0';

    if (strlen(prefix) == 0)
    {
        printf("\nNo Left Factoring Required.\n");
    }
    else
    {
        printf("\nLeft Factored Grammar:\n");
        printf("A -> %sA'\n", prefix);
        printf("A' -> %s | %s\n", p1 + i, p2 + i);
    }

    return 0;
}
