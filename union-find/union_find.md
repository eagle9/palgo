find: determine which subset a particular element is in. this can be used for determining if two elements are in the same subset
union: join two subsets into a single subset
disjoint set data structure. 
union find algorithm can be used to check whether an undirected graph contains cycle or not. 
0 - 1
0 - 2
2-1
subsets using both the v of the edge.  

initially, all slots of parent array are initialized to -1, which means
there is only one item in each subset. 
int [] parent = {-1,-1,-1}
with edge 0-1, find the subsets where 0 and 1 belong to.  they are in different subset, 
so we take the union. for taking the union, either make 0 as parent of 1 or vice-versa. 

parent = {1,-1,-1} //1 is made parent of 0
edge 1-2: different subsets, take union
parent = {1, 2,-1}
edge 0-2: same subset, cycle is found. 
