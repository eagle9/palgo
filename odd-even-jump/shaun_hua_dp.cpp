//idea forming hints:
//odd jump go up, but choose min ----> sounds like lower_bound & upper_bound
//even jump go down, but choose max

//can reach end? one valid jump after another? ----> dp with states

//hua dp with treemap/ordered_map binary search
//shaun has read and understood 95%

//runtime 116ms, faster than 49%, mem less than 27%
class Solution {
public:
  int oddEvenJumps(vector<int>& A) {
    const int n = A.size();
    map<int, int> m; //map from value to the min index of such value
    vector<vector<int>> dp(n + 1, vector<int>(2));
    //dp[i][0] --- can jump to end starting from i up
    //dp[i][1] --- can jump to end starting from i down
    dp[n - 1][0] = dp[n - 1][1] = 1;
    m[A[n - 1]] = n - 1;
    int ans = 1;
    for (int i = n - 2; i >= 0; --i) {
      auto o = m.lower_bound(A[i]); //first >= Ai, so Ai to Aj jump up
      if (o != m.end()) {
          int j = o->second;
          dp[i][0] = dp[j][1]; //boils down down jump from j
      }
      auto e = m.upper_bound(A[i]);//first > Ai, prev <= Ai
      if (e != m.begin()) { //found first > Ai
          int j = prev(e)->second;
          dp[i][1] = dp[j][0]; //boils down up jump from j
      }
      if (dp[i][0]) ++ans;
      m[A[i]] = i; //if A[i] already in map m, will be updated with smaller index
    }
    return ans;
  }
};
