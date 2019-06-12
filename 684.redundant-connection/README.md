684. Redundant Connection
Medium
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.

Topic: Tree, Union Find, Graph
Similar: 
Redundant Connection II,hard 
Accounts Merge,medium
Graph Valid  Tree

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 4

idea: 
tree no cycle, redundant edge results in cycle. 
detech cycle, then find the last edge in the cycle and return
input is a list of edges
nodes: 1 to N, edges list of u<v
dfs from any node, node 1, to find the cycle
dfs(node,visit) {
	for neighbor of node
		if nei not visited
			visit[nei]=true
			return dfs(nei,visit)
		else //nei visited
			found cycle from nei to node
			return nei //start of cycle
vector<bool> visit(N);
start = dfs(1,visit)
next = start's next node
pos of start,next
//this for loop is not very clean to return the answer
for (node = next; node != start; ) {
	next = node's next by edges	
	pos of node,next
	if pos > max_pos
		max_pos = pos
		last_edge = node,next
	node = next

	return last_edge
}  

how to use uf? 
for (u,v) in edge_list
	r1 = uf.find(u)
	r2 = uf.find(v)
	if r1 found f2 found 
		if r1 == r2 //same set
			return (u,v)
		else //r1 != r2
			uf.union(r1,r2)
			connect two sets by u,v
	else 
		if r1 not found
			add u to set r2,  since u connected to v
		else if r2 not found
			add v to set r1, since v connected to u
		else // r1 not found and r2 not found
			add(u).add(v), add u and v to the same set
my raw idea with uf was formed when i was not clear with uf
a set with union and find operation, find always return root
no insert op for uf set!!!!
so init constructor set with all elements
then union or find, union will call find
	

