79. Word Search
Medium
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

Companies: Bloomberg | 8 Microsoft | 7 Amazon | 7 Facebook | 6 Uber | 4 Google | 3 Zillow | 3 Snapchat | 3 Apple | 2 JPMorgan | 2

Topic: Array, Backtracking
Similar: Word search ii, hard
shaun idea:
for each i,j start of the grid
	vector visisted[i][j] boolean init false
	if helper(grid,i,j, word, 0, visited)
		return true
return false

bool helper(grid,i,j word, index) 
	if index == word.length()
		return true
	res = false
	if grid[i][j] == word[index]
		for (dx, dy): dir
			ni = i + dx;
			nj = j + dy;
			if ni nj outbound or  visited[ni][nj]
				continue
			visited[ni][nj] = true;
			res= helper(grid,ni,nj,word,index+1);
	return res			

add bound check and boolean visited[i][j]

