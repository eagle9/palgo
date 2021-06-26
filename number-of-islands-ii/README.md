305. Number of Islands II
Hard
20%
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:

Can you do it in time complexity O(k log mn), where k is the length of the positions?

Companies: Uber | 5 Google | 5 Amazon | 2 Snapchat | 2

Similar: Number of Islands Medium

Topic: Union Find

idea forming:
input: grid of mxn, vector<pair<int,int>> land
u_map<pair<int,int>,pair> parent_
u_map<pair<int,int>,int> rank_
u_map<pair<int,int>> root_set_

for each pair<int,int> land
	parent_[land] = land; //init land 
	rank_[land] = 0
prev = land0
vector<int> res{1};
for pair<int,int> land1 to land_n-1
	if land1 and prev neighboring 
		union(land1,prev)
	res.push_back(uf.size())
return res

bool neighbor(pair1,pair2)
	if pair1.first == pair2.fist
		return abs(pair1.second-pair2.second) == 1
	if pair1.second == pair2.second
		return abs(pair1.first-pair2.first) == 1
		
bool union(pair1, pair2) 
	//update root_set_ too

pair find(pair p)
	if (p != parents_[p]) //not root
		parents_[p] = find(parents_[p])
	return parents_[p]
int size()
	return root_set_.size()
		
