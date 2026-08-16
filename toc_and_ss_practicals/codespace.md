# Running a Lex (`.l`) Program Using GitHub Codespaces

**GitHub Codespaces** is an online **Linux development environment** that allows you to write, build, run, and test software without installing software on your local computer.

---
This guide explains how to write, compile, and execute a **LEX (Flex)** program directly in **GitHub Codespaces** without uploading any files beforehand.

---

## Prerequisites

- GitHub account
- Internet connection

---

## Step 1: Create a GitHub Codespace

1. Sign in to your GitHub account.
2. Click **+** → **New Codespace**.
3. Select any repository (or create a new empty repository if required).
4. Click **Create codespace**.

GitHub will launch a cloud-based Ubuntu environment.

---

## Step 2: Open the Terminal

Open a terminal.

```
Terminal → New Terminal
```

---

## Step 3: Install Required Packages

Update the package list.

```bash
sudo apt update
```

Install Flex and GCC.

```bash
sudo apt install flex gcc -y
```

Verify the installation.

```bash
flex --version
gcc --version
```

---

## Step 4: Create the Lex Source File

Create a new file.

```bash
nano lexer.l
```

Paste your Lex program into the file.

Save and exit:

- **Ctrl + O**
- **Enter**
- **Ctrl + X**

Verify the file.

```bash
ls
```

Output

```
lexer.l
```

---

## Step 5: Generate the C Source File

Generate the C source using Flex.

```bash
flex lexer.l
```

or

```bash
lex lexer.l
```

This creates

```
lex.yy.c
```

---

## Step 6: Compile the Program

Using the Flex library

```bash
gcc lex.yy.c -lfl
```

or using the Lex library

```bash
gcc lex.yy.c -ll
```

This creates the executable

```
a.out
```

---

## Step 7: Execute the Program

Run the executable.

```bash
./a.out
```

Enter the source program.

Example

```c
a=10+b;
```

After entering the input, press

```
Ctrl + D
```

to indicate **End of File (EOF)**.

---

## Sample Input

```c
int sum = a + 10;
```

---

## Sample Output

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

## Complete Workflow

```
Create GitHub Codespace
        │
        ▼
Install Flex and GCC
        │
        ▼
Create lexer.l
        │
        ▼
flex lexer.l
        │
        ▼
lex.yy.c
        │
        ▼
gcc lex.yy.c -lfl
        │
        ▼
a.out
        │
        ▼
./a.out
        │
        ▼
Enter Input
        │
        ▼
Press Ctrl + D
        │
        ▼
Generated Tokens
```

## Advantages of GitHub Codespaces

- No local installation required
- Cloud-based Ubuntu environment
- Built-in terminal and editor
- Accessible from any device
- Ideal for Flex/LEX and Compiler Design experiments
