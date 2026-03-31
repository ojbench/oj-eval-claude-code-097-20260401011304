# Problem 097 - Binary Search Tree kth Largest Element

## Problem Summary
Find the cnt-th largest element in a Binary Search Tree given in level-order array format.

## Submission History

### Submission 1 (ID: 766686)
- **Result**: Wrong Answer (0 points)
- **Issue**: Tried to parse custom format like "root = [12, 5, 18, 2, 9, 15, 20], cnt = 4"
- **Lesson**: The input format is simpler - just n, followed by n integers, then cnt

### Submission 2 (ID: 766688)
- **Result**: Memory Leak (0 points)
- **Issue**: Fixed input parsing but had memory leak issues with tree construction
- **Approach**: Standard level-order tree building with manual deleteTree function

### Submission 3 (ID: 766695)
- **Result**: Memory Leak (0 points)
- **Issue**: Still had memory leaks despite fixing null handling (0 as null indicator)
- **Approach**: Changed null indicator from -1 to 0

### Submission 4 (ID: 766698)
- **Result**: Memory Leak (0 points)
- **Issue**: Added destructor but still had memory leak detection on large inputs
- **Approach**: Used TreeNode destructor for automatic cleanup

### Submission 5 (ID: 766703) - BEST
- **Result**: 50 points (5/10 test cases passed)
- **Passed**: Test cases 1, 3, 5, 6, 8
- **Failed**: Test cases 2, 4, 7, 9, 10
- **Approach**: Simplified to sorting approach - ignore -1 nulls, sort remaining values

## Final Solution
The final approach reads all values, filters out -1 (null indicators), sorts in descending order, and returns the cnt-th element.

## Test Results Analysis
- Tests 1, 3, 5, 6, 8: PASSED - Likely cases without special null handling needed
- Tests 2, 4, 7, 9, 10: FAILED - Possibly have 0 as valid value, or different null handling

## Potential Improvements (if more submissions were available)
1. Don't filter any values - include all positive and zero values
2. Use actual BST traversal instead of sorting (O(h+k) vs O(nlogn))
3. Better understand the null indicator convention (-1 vs 0 vs something else)
4. Handle edge cases with negative values differently

## Final Score: 50/100 (5 submissions used)
