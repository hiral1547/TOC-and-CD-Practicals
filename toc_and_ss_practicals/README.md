# lextool
# Lexical Analyzer using LEX (Flex) Utility for UNIX

## Objective

To implement a Lexical Analyzer using the LEX utility in UNIX/Linux that identifies tokens such as keywords, identifiers, numbers, operators and delimiters.

---

## What is a Lexical Analyzer?

A lexical analyzer is the **first phase of a compiler**.

It reads the source program character by character and converts it into tokens.

Example:

Input

```c
int sum = a + 10;
```

Output

```
KEYWORD : int
IDENTIFIER : sum
OPERATOR : =
IDENTIFIER : a
OPERATOR : +
NUMBER : 10
DELIMITER : ;
```

---

## Requirements

- Ubuntu / Linux
- Flex (LEX)
- GCC Compiler

---

## Install Required Packages

Update package list

```bash
sudo apt update
```

Install Flex

```bash
sudo apt install flex
```

Install GCC

```bash
sudo apt install gcc
```

Verify installation

```bash
flex --version
```

---

## Project Files

```
lexer.l
README.md
```

---

## Generate C Program

```bash
lex lexer.l
```

or

```bash
flex lexer.l
```

This creates

```
lex.yy.c
```

---

## Compile

Using Lex library

```bash
gcc lex.yy.c -ll
```

or using Flex library

```bash
gcc lex.yy.c -lfl
```

This creates

```
a.out
```

---

## Run

```bash
./a.out
```

---

## Sample Input

```
a=10+b;
```

---

## Sample Output

```
IDENTIFIER : a
OPERATOR : =
NUMBER : 10
OPERATOR : +
IDENTIFIER : b
DELIMITER : ;
```

---

## Workflow

```
lexer.l
    │
    ▼
lex lexer.l
    │
    ▼
lex.yy.c
    │
    ▼
gcc lex.yy.c -ll
    │
    ▼
a.out
    │
    ▼
./a.out
```

---

## Important LEX Functions

### yylex()

Starts lexical analysis.

It scans the input and executes matching rules.

---

### yywrap()

Called when End Of File (EOF) is reached.

Return 1 → Stop scanning

Return 0 → Continue scanning another file

---

### yytext

Stores the current matched token.

Example

```
abc
```

```
yytext = "abc"
```

---

## Author

Hiral Patel
