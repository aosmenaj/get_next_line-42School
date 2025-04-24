# get_next_line-42School

> A function that reads a file line by line – part of the 42 School curriculum.

## 📚 Project Overview

**get_next_line** is a 42 project focused on file reading in C. The goal is to create a function that returns a line from a file descriptor each time it is called, handling buffer management, memory allocation, and edge cases like EOF and partial reads.

This project is a key step in learning how to manage memory and I/O in C, especially when working with file descriptors and dynamic strings.

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```
## ⚙️ How It Works

The `get_next_line` function works as follows:

- 📥 **Reads from a given file descriptor (`fd`)**: It reads data in chunks of `BUFFER_SIZE`, which is defined at the time of compilation.
- 🔁 **Returns one line at a time**: Each call to the function returns the next line from the file, including the newline character (`\n`) if present.
- 🧼 **Returns `NULL`** when there is nothing more to read or an error occurs.
- 📦 **Uses a static variable** to store leftover data between function calls, allowing the function to "remember" unread content.
- 📚 **Handles multiple file descriptors** simultaneously (BONUS): It manages separate buffers for each `fd` using static storage indexed per descriptor.

ℹ️ **Note:** You can define the buffer size at compile time using:
 ```bash
 gcc -D BUFFER_SIZE=42 ...
