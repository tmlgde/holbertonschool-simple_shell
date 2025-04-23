# 🐚 simple_shell

## 📜 Description

`simple_shell` is a minimalist UNIX shell implemented in C. This project was designed to understand how a command-line interpreter works internally, including:

- handling user input,
- searching for commands in the `PATH`,
- managing child processes using `fork` and `execve`,
- handling built-in commands like `exit`, `env`, etc.

The shell runs in both **interactive** and **non-interactive** modes. It handles EOF (Ctrl+D), extra whitespace, and displays an error when a command is not found.

---

## ⚙️ Compilation

To compile the project:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## ✅ Requirements

- Operating System: Ubuntu 20.04 LTS
- Compiler: `gcc` (GNU Compiler Collection)
- Recommended tools: `valgrind`, `git` (for version control)

---

## 💻 Usage

Start the shell:

```bash
./hsh
```

### Interactive Mode

```bash
$ ./hsh
$ ls
main.c  shell.c  README.md
$ /bin/echo Hello World
Hello World
$ exit
```

### Non-Interactive Mode

```bash
echo "/bin/ls -l" | ./hsh
```

---

## 📄 Man Page

A custom man page is available. To read it:

```bash
man ./man_1_simple_shell
```

---

## 🧪 Testing & Memory

### Manual Testing

```bash
echo "ls" | ./hsh
cat test_script.sh | ./hsh
```

### Memory Leak Check with Valgrind

```bash
valgrind --leak-check=full ./hsh
```

**Expected output:**

```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   All heap blocks were freed -- no leaks are possible
```

---

## 🔁 Flowchart

The diagram below illustrates the internal logic of the shell's main loop:

<div align="center">
    <img src="/flowchart.jpg" width="600" height="900">
</div>

---

## 📁 Main Files

| File Name             | Description                                      |
|-----------------------|--------------------------------------------------|
| `simple_shell.c`      | Main loop of the shell                           |
| `_getenv.c`           | Retrieves environment variables                  |
| `execve_command.c`    | Executes a command using `execve`                |
| `find_command_path.c` | Finds the absolute path of a command             |
| `free_tokens.c`       | Frees memory allocated for tokens                |
| `handle_builtin.c`    | Handles built-in commands (`exit`, `env`)        |
| `split_line.c`        | Splits input line into tokens                    |
| `main.h`              | Main header file                                 |
| `man_1_simple_shell`  | Man page for the `simple_shell` program          |

---

## 👨‍💻 Authors

- Tom LAGARDE - [GitHub](https://github.com/tmlgde)
- Clémence MEYNET - [GitHub](https://github.com/cmeynet)

