173. Binary Search Tree Iterator
Medium 1422 246 Favorite Share --- very worth

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Example:

BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false

Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
Accepted 211,619
Submissions 430,009

Contributor shtian

Companies:
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Facebook | 23 Microsoft | 5 Amazon | 5 Uber | 3 Google | 2 Bloomberg | 2 Apple | 2

Topic: Stack, Tree, Design

Similar:
Binary Tree Inorder Traversal Medium
Flatten 2D Vector Medium
Zigzag Iterator Medium
Peeking Iterator Medium
Inorder Successor in BST Medium
