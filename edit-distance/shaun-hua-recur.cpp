//shaun code from memory of hua's idea, accepted after 1 bug fix
//runtime 788ms, faster than 5%, mem less than 5% before 3rd bug fix
//runtime 12ms, faster than 85.85%, mem less than 10% after using string&
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        memo = vector<vector<int>> (len1+1, vector<int>(len2+1));
        return helper(word1, len1, word2, len2);
        
    }
private:
    vector<vector<int>> memo;
    //int helper(string word1, int i, string word2, int j) {
    int helper(string& word1, int i, string& word2, int j) {    //bug 3, should use string & parameter, much faster
        if (i == 0) return j;
        if (j == 0) return i;
        if (memo[i][j] > 0) return memo[i][j];
        int ans = INT_MAX;
        int cost = (word1[i-1] == word2[j-1])? 0: 1;
        //ans = min(ans, helper(word1, i-1, word2, j-1)); //bug 1, should +cost
        ans = min(ans, helper(word1, i-1, word2, j-1)+cost);
        ans = min(ans, helper(word1, i-1, word2, j) + 1);
        ans = min(ans, helper(word1, i,   word2, j-1)+1);
        return memo[i][j] = ans; //bug fix 2, store the ans into memo
    }
};
