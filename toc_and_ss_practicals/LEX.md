# 🌐 Running the Program Using an Online Compiler
### Lexical Analyzer in C (Without Using Lex/Flex)
If you do not have a C compiler installed on your computer, you can run this lexical analyzer directly in an online compiler.

## Option 1: OnlineGDB (Recommended)

### Step 1: Open OnlineGDB

Visit:

https://www.onlinegdb.com/online_c_compiler

### Step 2: Select Language

Ensure the language is set to **C**.

### Step 3: Create a New Program

Delete the default code and paste the contents of `lexer.c`.

### Step 4: Run the Program

Click the **Run** button.

### Step 5: Enter the Input

When prompted, enter a C statement.

Example:

```c
int a = 10;
```

Press **Enter**.

### Step 6: View the Output

The program classifies the input into different tokens.

Example Output:

```
Keyword         : int
Identifier      : a
Operator        : =
Constant        : 10
Special Symbol  : ;
```

---

## Option 2: Programiz Online Compiler

### Step 1

Open:

https://www.programiz.com/c-programming/online-compiler

### Step 2

Remove the default program.

### Step 3

Paste the lexical analyzer source code.

### Step 4

Click **Run**.

### Step 5

Provide the input when prompted.

Example:

```c
float total = a + 25.5;
```

### Step 6

Observe the generated tokens.

---

## Option 3: OneCompiler

### Step 1

Open:

https://onecompiler.com/c

### Step 2

Replace the sample code with `lexer.c`.

### Step 3

Click **Run**.

### Step 4

Enter the sample input.

### Step 5

View the output.

---

# 📝 Sample Inputs

### Example 1

Input

```c
int a = 10;
```

Output

```
Keyword         : int
Identifier      : a
Operator        : =
Constant        : 10
Special Symbol  : ;
```


---

### Example 2

Input

```c
if(x>100)
{
    y=x+1;
}
```

Output

```
Keyword         : if
Special Symbol  : (
Identifier      : x
Operator        : >
Constant        : 100
Special Symbol  : )
Special Symbol  : {
Identifier      : y
Operator        : =
Identifier      : x
Operator        : +
Constant        : 1
Special Symbol  : ;
Special Symbol  : }
```

---

# 🎯 Advantages of Using an Online Compiler

- No installation required.
- Runs directly in a web browser.
- Works on Windows, macOS, and Linux.
- Easy to test and modify the code.
- Suitable for students and laboratory practicals.
- Accessible from anywhere with an internet connection.

---

## 💻 Source Code

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {
    "int", "float", "char", "if", "else", "while",
    "for", "return", "void", "double"
};

int isKeyword(char str[])
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char input[500];
    char token[50];
    int i = 0, j = 0;

    printf("Enter a C statement:\n");
    fgets(input, sizeof(input), stdin);

    while(input[i] != '\0')
    {
        if(isspace(input[i]))
        {
            i++;
            continue;
        }

        if(isalpha(input[i]) || input[i] == '_')
        {
            j = 0;

            while(isalnum(input[i]) || input[i] == '_')
            {
                token[j++] = input[i++];
            }

            token[j] = '\0';

            if(isKeyword(token))
                printf("%-15s : %s\n", "Keyword", token);
            else
                printf("%-15s : %s\n", "Identifier", token);
        }

        else if(isdigit(input[i]))
        {
            j = 0;

            while(isdigit(input[i]) || input[i] == '.')
            {
                token[j++] = input[i++];
            }

            token[j] = '\0';

            printf("%-15s : %s\n", "Constant", token);
        }

        else if(strchr("+-*/=%<>!", input[i]))
        {
            printf("%-15s : %c\n", "Operator", input[i]);
            i++;
        }

        else if(strchr("(){}[],;#", input[i]))
        {
            printf("%-15s : %c\n", "Special Symbol", input[i]);
            i++;
        }

        else
        {
            printf("%-15s : %c\n", "Unknown", input[i]);
            i++;
        }
    }

    return 0;
}
```

---
