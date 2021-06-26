//first try TLE
//second try with hashtable, runtime 1020ms, faster than 5%, mem less than 100%
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        vector<int> ans(n);
        unordered_map<string,int> m;
        for (string w: words) {
            m[w] = f(w);
        }
        for (int i = 0; i < n; ++i) {
            int f1 = f(queries[i]);
            int count = 0;
            for (string w: words) {
                if (f1 < m[w]) count++;
            }
            ans[i] = count;
        }
        return ans;
    }
private:
    //freq of smallest char
    int f(string word) {
        sort(word.begin(), word.end());
        int i = 0;
        
        while (i+1 < word.size() && word[i] == word[i+1]) i++;
        //now i != i+1, w[i+1] new char
        //   i  i+1
        //aa a  b
        return i+1; 
    }
};
