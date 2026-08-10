# Lex Practical – General Setup and Execution Steps

## 1. Install Required Packages

Run these commands in the Codespace terminal:

```bash
sudo apt update
sudo apt install flex gcc -y
```

---

## 2. Create the Lex Program

Create a file with the `.l` extension.

Example:

```text
program.l
```

Write the Lex/Flex program and save it.

---

## 3. Create the Input File (If Required)

If the program requires an external input file, create it in the same directory.

Example:

```text
input.txt
```

If no input file is required, skip this step.

---

## 4. Generate the C File

```bash
flex -o program.c program.l
```

---

## 5. Compile the Program

```bash
gcc program.c -lfl -o program
```

---

## 6. Run the Program

### If an input file is required

```bash
./program input.txt
```

### If no input file is required

```bash
./program
```

---

## 7. Complete Commands

### With an input file

```bash
sudo apt update
sudo apt install flex gcc -y

flex -o program.c program.l
gcc program.c -lfl -o program
./program input.txt
```

### Without an input file

```bash
sudo apt update
sudo apt install flex gcc -y

flex -o program.c program.l
gcc program.c -lfl -o program
./program
```

---

## 8. Folder Structure

### With an input file

```text
project/
├── program.l
├── program.c
├── program
└── input.txt
```

### Without an input file

```text
project/
├── program.l
├── program.c
└── program
```
