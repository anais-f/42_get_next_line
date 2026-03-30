# Get Next Line

A project from 42 that implements a function to read lines from a file descriptor. Think of it as a custom version of `getline()` but way more manual – and way more educational.

## What's the point?

You get to build a line-reading function from scratch using only basic syscalls. The fun part? You have to manage memory, handle partial reads, and buffer stuff yourself. It's less "here's a library function" and more "now you understand why we have library functions."

## How it works

The main function `get_next_line(int fd)` reads from a file descriptor and returns the next complete line, including the newline character (unless EOF). Call it again and you get the next line. Simple concept, less simple implementation.

There's also a bonus version if you want to handle multiple file descriptors at once without stepping on each other's data.

## Building

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c *.c
ar -rc libgnl.a *.o
```

The `BUFFER_SIZE` is configurable – tweak it to see how it affects performance.

## Files

- **get_next_line.c / get_next_line.h** – The main implementation
- **get_next_line_utils.c** – Helper functions (string ops, memory stuff)
- **get_next_line_bonus.c / get_next_line_bonus.h** – Multi-fd support
- **main.c** – Quick test file

## Bonus round

If you're into it, the bonus version lets you handle multiple file descriptors without them interfering with each other. Uses static arrays instead of a single static variable.
