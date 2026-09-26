\# Complexity Analysis



\## BST Search



\- Best Case: O(1)

\- Average Case: O(log n)

\- Worst Case: O(n)

\- Space Complexity: O(n)



\## Linear Search



\- Best Case: O(1)

\- Average Case: O(n)

\- Worst Case: O(n)

\- Extra Space Complexity: O(1)



\## BST Insertion



\- Average Case: O(log n)

\- Worst Case: O(n)



\## Inorder Traversal



\- Time Complexity: O(n)



\## Effect of Key Length



The identification numbers are stored as strings and compared using strcmp().

The length of the key can affect the time required for an individual string

comparison. Longer keys may require more character comparisons, especially

when they have common prefixes.



\## Effect of Insertion Order



The insertion order affects the structure and height of a BST. For the given

data, the original insertion order produced a height of 6, while the changed

insertion order produced a height of 5.



A balanced BST can provide O(log n) search performance, while a highly

skewed BST can degrade to O(n).

