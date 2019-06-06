//shaun own idea, accepted after 1 bug fix
//runtime 12ms, faster than 99%, mem less than 27%
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 != word2) {
            return helper(words, word1, word2);
        }else { //word1 == word2
            int n = words.size();
            int ans = n, i1 = -1;
            for (int i = 0; i < n; ++i) {
                //if (words[i] == word1 && i1 >= 0)  ---- bug
                if (words[i] == word1) {
                    if (i1 >= 0)
                        ans = min(ans, abs(i - i1));
                    i1 = i;
                }
            }
            return ans;
        }
    }
    
private:
    int helper(vector<string>& words, string word1, string word2) {
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
