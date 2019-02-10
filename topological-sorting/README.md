Lintcode # 127. Topological Sorting

Difficulty: Medium

http://lintcode.com/en/problem/topological-sorting/

Given an directed graph, a topological order of the graph nodes is defined as follow:

* For each directed edge A -> B in graph, A must before B in the order list.
* The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

**Clarification**  
Learn more about representation of graphs

**Example**  
For graph as follow:
  ->  1   -> 4
0 ->  2   -> 4
          -> 5
  ->  3 -> 4
        -> 5
The topological order can be:
```
[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
```
Challenge: can you do it in both BFS and DFS
Related: Course schedule IV, course schedule, course schedule ii, sequence reconstruction
