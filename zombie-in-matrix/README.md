# 598. Zombie in Matrix

Difficulty: Medium

http://www.lintcode.com/en/problem/zombie-in-matrix/

Given a 2D grid, each cell is either a wall 2, a zombie 1 or people 0 (the number zero, one, two).Zombies can turn the nearest people(up/down/left/right) into zombies every day, but can not through wall. How long will it take to turn all people into zombies? Return -1 if can not turn all people into zombies.

**Example**  
Given a matrix:
```
0 1 2 0 0
1 0 0 2 1
0 1 0 0 0
```
return 2

idea: 1 day a zombie(1) turns its neighbors into zombies, new zombies do the same thing to expand
bfs expanding
vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
pair<int,int> into queue
put all zombies grid[i][j] == 1 into queue
count_people =  ?
count_days = 0;
while (!q.empty()) {
	int n = q.size();
	//one day for all zombies in q
	count_days++;
	for (int i = 0; i < n; ++i) {
			auto p = q.front(); q.pop();
			for (auto d: dirs) {
				int i = p.first + d[0], j = p.second + d[1];
				if (i outbound || j outbound) continue;
				if (grid[i][j] == 0) {
					grid[i][j] = 1; //people to zombie 
					count_people--;
					//if (count_people == 0) return count_days;
					queue.push(make_pair(i,j)); //push new zombie into queue
				}
			}
	}
}
if (count_people == 0) return count_days;
else return -1;
