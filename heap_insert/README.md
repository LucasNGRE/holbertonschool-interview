# Heap Insert

This project implements a Max Binary Heap and the operation to insert a value
into it, keeping the heap property.

## Data structures

```c
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

## Files

| File | Description |
| ---- | ----------- |
| `binary_trees.h` | Header file with data structures and function prototypes |
| `0-binary_tree_node.c` | `binary_tree_node` — creates a binary tree node |
| `1-heap_insert.c` | `heap_insert` — inserts a value into a Max Binary Heap |

## Compilation

```sh
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c *-main.c *.c -o heap
```

## Requirements

- Ubuntu 14.04 LTS, gcc 4.8.4 with `-Wall -Werror -Wextra -pedantic`
- Betty style
- No global variables
- No more than 5 functions per file
