\# Final Conclusion



A Binary Search Tree was implemented to organize the given government

identification numbers. The inorder traversal of the BST produced the

identification numbers in lexicographical order.



BST Search and Linear Search were compared using selected identification

numbers. The experimental results showed that BST Search required fewer

comparisons for some of the selected IDs, while for some IDs both methods

required the same or similar number of comparisons.



The experiment also showed that insertion order affects the height of a BST.

For the given data, the original insertion order produced a height of 6,

whereas the changed insertion order produced a height of 5.



Key length can affect the cost of string comparison because the IDs are

compared character by character using strcmp(). However, insertion order has

a greater effect on the height and overall search path of the BST.



Theoretical analysis shows that a balanced BST provides O(log n) average

search time, while a skewed BST can have O(n) worst-case search time. Linear

Search has O(n) average and worst-case time.



Therefore, as the database grows, maintaining a reasonably balanced search

tree is important for efficient searching. A self-balancing BST such as an

AVL tree or Red-Black tree can be considered when consistently efficient

search performance is required.

