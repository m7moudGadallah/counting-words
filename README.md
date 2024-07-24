# Word Count

## Description

- This is a CS homework that builds a simple word count program c program.
- This program reads input from a file or standard input and counts the number of words int the input and prints the result to standard output and also count frequency of each word and print the result to standard output.
- This program should be able to pipe input from another program.

## Features

- This program reads input from a file or standard input.
- This program counts the number of words in the input.
- This program counts the frequency of each word in the input.
- This program prints the number of words in the input to standard output.
- This program offers command options to print the frequency of each word in the input to standard output.
  - `c` option prints the word count to standard output.
  - `f` option prints the frequency of each word to standard output.
  - `s` option prints the word frequency list sorted by frequency to standard output.
  - `r` option prints the word frequency list in reverse order to standard output.

## How to run

- To run the program, you need to compile the program first.
- You can compile the program by running `make` command in the terminal.
- After compiling the program, you can run the program by running `./wordcount` command in the terminal.

### Examples

- You can run the program by running `./wordcount` command in the terminal.
- You can run the program by running `./wordcount < input.txt` command in the terminal.
- You can run the program by running `cat input.txt | ./wordcount` command in the terminal.
- You can run the program by running `./wordcount -fcs input.txt` command in the terminal.

> Note: You can replace `input.txt` with any file you want to count words.
