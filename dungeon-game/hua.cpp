/*
Runtime: 12 ms, faster than 100.00% of C++ online submissions for Dungeon Game.
Memory Usage: 10.4 MB, less than 100.00% of C++ online submissions for Dungeon Game.
huahua dp idea

*/
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {      
    const int m = dungeon.size();
    const int n = dungeon[0].size();
 
    // hp[y][x]: min hp required to reach bottom right (P).
    vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
    hp[m][n - 1] = hp[m - 1][n] = 1;
 
    for (int y = m - 1; y >= 0; --y)
      for (int x = n - 1; x >= 0; --x)
        hp[y][x] = max(1, min(hp[y + 1][x], hp[y][x + 1]) - dungeon[y][x]);
 
    return hp[0][0];
  }
};
