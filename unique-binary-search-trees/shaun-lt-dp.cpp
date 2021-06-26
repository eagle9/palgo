/*
shaun 2nd round init thought cutting: 
all BSTs from 1 to i-1 done, dp[i-1]
now add i, for each BST in dp[i-1], add i as the right most node
dp[i] += dp[i-1]
i as root, all trees in dp[i-1] as the left subtree
dp[i] += dp[i-1]
not progressing, check with lt idea
why it is not cutting in, because it is dp[i-1] not enough to get dp[i]
the draw back of my thinking is that:  it's not always working to get dpi with i-1
think wider options
think structure: try different root, bingo, clever to do j+1 to i ==> 1 to i-1 transformation

lt dp idea, cutting is: with 1 to i,  try j(1..i) as the root
left part is 1 to j-1, right part is j+1 to i
j+1 to i ===> 1 to i-j
so dp[i] = dp[j-1] * dp[i-j]

runtime 0ms, faster than 100%, mem less than 74%
*/


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1); // (size)
        dp[0] = 1;
        dp[1] = 1;
        //for 1 to i, j from 1 to i, j as the root, 1 to j-1 left tree, j+1 to i right tree (i - j-1+1 = i-j) 
        //1     j        i
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1]* dp[i-j];
            }
        }
        return dp[n];
    }
};
