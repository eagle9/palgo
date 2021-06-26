//shaun own idea, accepted after 1 bug fix
//runtime 16ms, faster than 92.70%, mem less than 22%
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size(), i1 = -1, i2 = -1;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (words[i] == word1) i1 = i;
            if (words[i] == word2) i2 = i;
            //if (i1 > 0 && i2 > 0) ans = min(ans, abs(i1- i2)); //>0 to >=0
            if (i1 >= 0 && i2 >= 0) ans = min(ans, abs(i1- i2));
        }
        return ans;
    }
};
