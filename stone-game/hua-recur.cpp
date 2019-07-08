// hua recur with memo minimax 
// runtime 36ms, faster than 27%, mem less than 11%
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    m_ = vector<vector<int>>(n, vector<int>(n, INT_MIN));
    return score(piles, 0, n - 1) > 0;
  }
private:
  vector<vector<int>> m_;
  int score(const vector<int>& piles, int l, int r) {
    if (l == r) return piles[l];
    if (m_[l][r] == INT_MIN)
      m_[l][r] = max(piles[l] - score(piles, l + 1, r),
                     piles[r] - score(piles, l, r - 1));
    return m_[l][r];
  }
};

