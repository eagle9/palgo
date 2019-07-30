// Follow up, using binary search and hash table
//cutting: shaun came up the same idea, but not clear about the hash table, chars could be repeating in t, so the hash table should be char to vector<int>, char to its many indexes, for each char in s, we make sure we can find the char in hash table, and find a index that > previous index, otherwise, return false
//runtime 108ms, faster than 12%, mem less than 11%
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pre = -1, n = t.size();
        unordered_map<char, vector<int>> char2pos; //char to its position in t, could be many, so char to vector<int>
        for (int i = 0; i < n; ++i) char2pos[t[i]].push_back(i);
        
        //go through chars in s, find its index, should be > pre(prev char's index)
        for (char c : s) {
            //upper_bound return first it whose value > pre
            auto it = upper_bound(char2pos[c].begin(), char2pos[c].end(), pre);
            if (it == char2pos[c].end()) return false;
            pre = *it;
        }
        return true;
    }
private:
    //find the firs index of element > target
    int my_upper_bound(vector<int>& a, int target) {
        return 0;
    }
    

    
};
