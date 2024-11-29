# Min Heap Operations
This program demonstrates the use of a Min-Heap data structure to perform heap sort operations on a vector of integers. It also tracks and outputs the number of swap operations during insertions and deletions.

## Features
- Implementation of Min-Heap with:
    - **Insertions** and **Deletions** operations.
    - Maintenance of Min-Heap property through `heapifyUp` and `heapifyDown` algorithms.
    - Counters for tracking swap operations during insertions and deletions.
- Heap Sort:
    - Sorts a vector using heap operations.
    - Demonstrates sorting with original, ascending, and descending order vector.
- Utility Functions for:
    - Sorting vectors in ascending and descending order.
    - Counting swap operations for performance analysis.

## Running the Program with File Input
You can prepare an input file (e.g., input.in) with the required format, and run the program by piping the file's contents into the executable. 

## Input Format
1. An integer `n` specifying the number of elements.
2. `n` integers to populate the original, ascending, and descending order.

### Example File: input.in
```sh
5 4 1 3 9 7
```

### Expected Output
```sh
original: 1 + 2
ascending: 0 + 4
descending: 6 + 2
```

## Output
1. The number of swap operations during insertion and deletion for:
    - Original vector.
    - Ascending order vector.
    - Descending order vector.

## How to Run
1. Compile the program using C++ compiler:  
```sh
g++ -o MinHeapOperations MinHeapOperations.cpp
```

2. Run the program:  
You can use `cat` command to pipe the contents of the file into the program:  
```sh
cat input.in | ./MinHeapOperations
```

## Contributing
Feel free to fork this reporsitory and submit a pull request for new featues, optimisations, or documentation updates.