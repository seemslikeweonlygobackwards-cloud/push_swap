*This project has been created as part of the 42 curriculum by mavanesy and amghazar.*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using a limited set of operations on two stacks — **stack A** (the input) and **stack B** (a temporary buffer) — while minimizing the total number of operations performed.

The program receives a list of integers as arguments, then outputs the sequence of instructions needed to sort them in ascending order on stack A.

### Available Operations

| Operation | Effect |
|-----------|--------|
| `sa` | Swap the top two elements of stack A |
| `sb` | Swap the top two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A upward (top becomes bottom) |
| `rb` | Rotate stack B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (bottom becomes top) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Instructions

### Compilation

```bash
make
```

This will produce the `push_swap` executable.

### Execution

```bash
./push_swap 3 1 4 1 5 9 2 6
```

The program prints the list of operations to standard output, one per line.

### Optional Flags

The program supports an optional first argument to override the sorting strategy:

```bash
./push_swap --simple  3 2 1
./push_swap --medium  3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1   # default
./push_swap --bench   3 2 1    # enable benchmarking output
```

### Cleaning

```bash
make clean    # remove object files
make fclean   # remove object files and executable
make re       # full recompile
```

---

## Algorithms

This project implements an **adaptive strategy** that selects a sorting algorithm based on both the size of the input and its degree of disorder. All three strategies work by assigning each number a **normalized index** (rank) before sorting, which eliminates the need to deal with arbitrary integer values.

### Disorder Measurement

Before choosing a strategy, the program computes a **disorder score** — the ratio of inversions to the maximum possible inversions (i.e., the number of pairs `(i, j)` where `i < j` but `a[i] > a[j]`, divided by `n*(n-1)/2`). A score of `0.0` means perfectly sorted; `1.0` means fully reversed.

This measurement drives the adaptive strategy:
- **Score < 0.2** → use `simple_sort` (the input is nearly sorted)
- **Score ≥ 0.2** → use `medium_sort`
- Inputs of 3 elements or fewer always use `simple_sort`

### Simple Sort (Insertion-based)

For small or nearly sorted inputs, the program uses a minimum-extraction approach:

1. Repeatedly find the minimum element in stack A and rotate it to the top (using `ra` or `rra` depending on which direction is shorter).
2. Push it to stack B with `pb`.
3. Repeat until 3 elements remain in stack A.
4. Sort the remaining 3 with hardcoded logic for all permutations of 3 elements (`sort3`).
5. Push everything back from stack B to stack A with `pa`.

This is efficient for small inputs (≤ ~20 elements) and nearly sorted sequences because few rotations are needed to find each minimum.

### Medium Sort (Chunk-based Greedy)

For medium-sized or moderately disordered inputs, the program uses a **chunk sort**:

1. Divide the index range `[1, n]` into chunks of approximately 20 elements each (minimum 5 chunks).
2. Scan stack A repeatedly; for each chunk in order, push all elements belonging to it onto stack B with `pb`. Elements not belonging to the current chunk are rotated past with `ra`.
3. Once all elements are on stack B, greedily pull the maximum remaining element from stack B back onto stack A: find the position of the maximum, then rotate B the short way (`rb` or `rrb`) to bring it to the top, then `pa`.

Chunking reduces the number of rotations needed during the push phase, and the greedy pull phase reconstructs the sorted order efficiently.

### Complex Sort (Radix Sort)

For large inputs, the program uses **LSD (least-significant digit) radix sort** on the binary representation of the normalized indices:

1. Compute how many bits are needed to represent `n - 1` (the maximum index).
2. For each bit from least significant to most significant:
   - Scan all elements currently in stack A.
   - If the current bit of the top element's index is `0`, push it to stack B (`pb`).
   - If the bit is `1`, rotate it to the bottom of stack A (`ra`).
   - After processing all elements, push everything back from stack B to stack A (`pa`).
3. After `k` passes (where `k` is the number of bits), stack A is sorted.

This guarantees `O(n log n)` operations in the worst case and is the most efficient strategy for large, fully random inputs.

### Strategy Selection Summary

| Input Size | Disorder     | Strategy Used  |
|------------|--------------|----------------|
| ≤ 3        | any          | `simple_sort`  |
| any        | < 0.2        | `simple_sort`  |
| any        | 0.2 – 0.5    | `medium_sort`  |
| any        | ≥ 0.5        | `complex_sort` |

---

## Resources

- Grokking Algorithms: An Illustrated Guide for Programmers and Other Curious People
- [Time Complexities of all Sorting Algorithms — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Sorting Algorithm Visualizer](https://visualgo.net/en/sorting)

### AI Usage

AI tools were used for:
- Debugging
- Documentation structuring

All implementation logic was tested by the authors.
