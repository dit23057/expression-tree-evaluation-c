# Arithmetic Expression Binary Tree in C

A C program that builds and evaluates arithmetic expressions using a **binary tree** data structure.

## Overview

This project parses a mathematical expression entered by the user, stores it in a binary tree, and provides operations such as:

- Expression evaluation
- Prefix form display
- Postfix form display
- Tree memory deallocation

The program uses:

- **Binary Tree** for representing the expression
- **Stack** for temporary construction of the tree
- **Dynamic memory allocation** with `malloc()` and `free()`

## Features

- Accepts arithmetic expressions from user input
- Supports the following operators:
  - `+`
  - `-`
  - `*`
  - `/`
  - `%`
- Evaluates the expression recursively
- Prints:
  - **Prefix notation**
  - **Postfix notation**
- Frees allocated memory after execution

## Data Structures

### `TreeNode`
Represents a node in the binary expression tree.

- Stores either:
  - an integer number, or
  - an arithmetic operator
- Contains pointers to:
  - left child
  - right child

### `StackNode`
Used during tree construction.

- Holds a pointer to a `TreeNode`
- Points to the next stack element

## Program Menu

When the program runs, the user can choose from the following options:

1. Enter an arithmetic expression
2. Evaluate the expression
3. Print prefix form
4. Print postfix form
5. Print binary tree
0. Exit
