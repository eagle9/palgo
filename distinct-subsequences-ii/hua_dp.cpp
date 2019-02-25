/*
Time complexity: O(N*26)

Space complexity: O(N*26) -> O(26)
huahua dp
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Distinct Subsequences II.
Memory Usage: 9.2 MB, less than 93.33% of C++ online submissions for Distinct Subsequences II.
*/

class Solution {
public:
  int distinctSubseqII(string S) {
    constexpr int kMod = 1e9 + 7;
    std::vector<int> counts(26);
    for (char c : S)
      counts[c - 'a'] = accumulate(begin(counts), end(counts), 1L) % kMod;
    return accumulate(begin(counts), end(counts), 0L) % kMod;
  }
};
