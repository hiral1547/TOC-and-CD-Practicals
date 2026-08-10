// Implementation of Finite Automata and String Validation
// Accept binary strings ending with "01"

/*
Transition table: Accept binary strings ending with "01"

| Current State | Input = 0 | Input = 1 | Final State |
| ------------- | --------- | --------- | ----------- |
| → q0 (Start)  | q1        | q0        | No          |
| q1            | q1        | q2        | No          |
| *q2           | q1        | q0        | Yes         |

Algorithm
    1. Start from the initial state (q0).
    2. Read the input string character by character.
    3. Change the current state according to the DFA transition table.
    4. If any character is not in the alphabet (0 or 1), report an invalid input.
    5. After reading the complete string: 
       - If the current state is a final state, accept the string.
       - Otherwise, reject the string.

Formal Definition of DFA
    1. States (Q) = {q0, q1, q2}
    2. Input Alphabet (Σ) = {0, 1}
    3. Start State = q0
    4. Final State (F) = {q2}
    5. Transition Function (δ) = Given by the transition table above.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++) {

        switch(state) {

            case 0:
                if(str[i] == '0')
                    state = 1;
                else if(str[i] == '1')
                    state = 0;
                else {
                    printf("Invalid Input!\n");
                    return 0;
                }
                break;

            case 1:
                if(str[i] == '0')
                    state = 1;
                else if(str[i] == '1')
                    state = 2;
                else {
                    printf("Invalid Input!\n");
                    return 0;
                }
                break;

            case 2:
                if(str[i] == '0')
                    state = 1;
                else if(str[i] == '1')
                    state = 0;
                else {
                    printf("Invalid Input!\n");
                    return 0;
                }
                break;
        }
    }

    if(state == 2)
        printf("String Accepted.\n");
    else
        printf("String Rejected.\n");

    return 0;
}
