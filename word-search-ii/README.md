212. Word Search II
Hard
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:
Input: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.
Companies: Amazon | 11 Google | 5 Microsoft | 4 Facebook | 3 Airbnb | 2 Houzz | 2
Topic: Backtracking, Trie
Similar: word search
Hints: 
You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

idea: 
for each ij in the grid
  	ch = grid[i][j]
	pref = ch, any words that with pref?	
	if yes next i,j up down left right in bound
	pref += grid[ni,nj]
	keep recur of dfs if pref has words
	if pref has words by trie
	for up down left right ni, nj
		helper(grid,ni,nj,visited,res)
	if pref/trie reach leaf, add word corresponding to leaf to res 

void helper(pref,grid,i,j,visited,res,trie) {
	if i,j out of bound return 	
	if visited[i][j] return
	if pref reach leaf in trie
		//found a word
		res.push_back(pref)
		return
	//extending pref
	pref = pref + grid[i][j]
	if pref + grid[i][j] has words according to trie 
		pref1 = pref + grid[i][j]
		visited[i][j] = true
		//recur
		helper(pref1, gird, i-1, j, visited, res, trie);
		helper(pref1, gird, i+1, j, visited, res, trie);
		helper(pref1, gird, i, j-1, visited, res, trie);
		helper(pref1, gird, i, j+1, visited, res, trie);
		visited[i][j] = false;
private: 
	TrieNode * root;
struct TrieNode {
	char letter;	
	vector<TrieNode*> children(26);
}
	//get vector of words that shared pref
	vector<string> getPrefs(TrieNode * root, string pref)
		int len = pref.size();
		TrieNode cur = root;
		for (int i = 0; i < len; i++){
			int ic = pref[i] - 'a';
			cur.children[ic] =   
		}
		
}
	


}
	
