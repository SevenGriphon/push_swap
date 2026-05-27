*This activity has been created as part of the 42 curriculum by ldoucet, alnoviko.*

# Push_swap

## Description

Push_swap is a sorting algorithm project using two stacks (`a` and `b`) and a limited set of operations. The goal is to sort a list of integers placed in stack `a` in ascending order, using the minimum number of operations possible.

The program implements four distinct sorting strategies, automatically selected based on the predicted number of operations required by each algorithm, or forced via command-line flags.

Available operations:
- `sa` / `sb` / `ss` — swap top two elements
- `pa` / `pb` — push top element from one stack to the other
- `ra` / `rb` / `rr` — rotate (top becomes last)
- `rra` / `rrb` / `rrr` — reverse rotate (last becomes top)

## Instructions

### Compilation

```bash
make        # build push_swap
make clean  # remove .o files
make fclean # remove .o files and the binary
make aclean # build push_swap and remove .o files
make re     # fclean + rebuild
```

This produces the `push_swap` binary. Requires a C compiler (`cc`), the `libft` sources in `libft/`, and the custom `printf` library in `printf/` (provides `ft_printf_fd` for stderr output).

### Execution

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
```

**Strategy flags (optional):**
| Flag | Algorithm | Complexity |
|---|---|---|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | Radix sort (LSD binary) | O(n log n) |
| `--adaptive` | Auto-select by disorder | O(n) / O(n√n) / O(n log n) |

If no flag is given, `--adaptive` is the default.

**`--bench` flag:** Prints statistics to stderr after sorting (disorder %, strategy used, total operations, per-operation counts). Implemented in `bench.c` via `print_bench()`.

### Usage examples

```bash
# Sort 6 numbers (adaptive by default)
./push_swap 2 1 3 6 5 8

# Force the O(n²) strategy
./push_swap --simple 5 4 3 2 1

# Force O(n log n) and verify with checker
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG

# Benchmark on 500 random numbers
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt
```

### Error handling

```bash
./push_swap 0 one 2 3   # Error: non-integer argument
./push_swap 3 2 3       # Error: duplicate value
```

Errors are printed as `Error` followed by a newline on stderr.

## Algorithms

### 1. Simple — O(n²) : Selection sort

All elements are pushed from `a` to `b`. Then, on each step, the maximum of `b` is brought to the top (using `rotate` or `reverse_rotate`, whichever costs fewer moves) and pushed back to `a`. This naturally reconstructs `a` in ascending order.

**Complexity argument:** For n elements, finding and rotating to the max is O(n) per element, repeated n times → O(n²) operations total.

### 2. Medium — O(n√n) : Chunk-based sort

The value range [min, max] is divided into √n equal chunks. Elements belonging to each chunk are pushed from `a` to `b` in order (rotating through `a` to find them). Once all chunks are in `b`, the maximum is repeatedly brought to the top and pushed back to `a`.

**Complexity argument:** √n chunks × O(n) rotations to collect each chunk = O(n√n) operations for the push phase. The pull-back phase is O(n) total → overall O(n√n).

### 3. Complex — O(n log n) : Binary LSD Radix sort

Values are first normalized to ranks (0 to n−1) to handle negative numbers. Then, for each bit position from LSB to MSB, elements with a `0` bit are pushed to `b` and rotated, while elements with a `1` bit stay in `a` (rotated) (or the other way around if it would cost less operations). After each pass, all elements are merged back. log₂(n) passes × O(n) operations per pass → O(n log n).

**Complexity argument:** The number of bit positions needed is ⌈log₂(k)⌉ where k is the largest number in the list. If we assume that k = n (for example the numbers are shuffled [0, n]) that simplifies to ⌈log₂(n)⌉. Each pass is O(n) push/rotate operations → O(n log n) total.

### 4. Disorder metric

The disorder metric is computed before any moves: it counts the fraction of pairs (i, j) where i < j but `a[i] > a[j]`, giving a value in [0, 1].

### 4. Adaptive — disorder-driven selection

Adaptive sort tries to predict the cost of each algorithm using it's complexity and chooses the algorithm with the smallest predicted cost.

| Method | Aproximised complexity | O complexity |
|---|---|---|
| Bubble sort on `a` (swap + rotate) | (n/2)\*n+n | O(n) |
| Chunk-based sort | 2n\*√n | O(n√n) |
| Chunk-based sort | (log k + 1)\*2n | O(n log k) |

The algorithm also verifies that the disorder of the list isn't 0.

**Threshold rationale:**
The only threshhold used is 0, which determines wether the list is already sorted, to avoid unnecessary operations.

**Space complexity:** O(n) auxiliary space (stack `b`) for all strategies.

## Resources

### References
- [Visualgo — Sorting algorithms visualized](https://visualgo.net/en/sorting)
- [Wikipedia — Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Wikipedia — Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Wikipedia — Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)
- [Wikipedia — Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [The Art of Computer Programming — Donald Knuth](https://en.wikipedia.org/wiki/The_Art_of_Computer_Programming)

### AI usage

AI (Claude) was used during this project for:
- **Debugging assistance**: identifying logic errors
- **README drafting**: structuring and writing this documentation.

### Contributions
**alnoviko**:
    - libft  
    - genral operations  
    - radix  
    - main  
    - Makefile  
    - header file  
**ldoucet**:
    - pritnf_fd  
    - insertion sort
    - bucket sort
    - error handling  
    - bench flag  
    - adaptive algorithm  
    - basic operations  