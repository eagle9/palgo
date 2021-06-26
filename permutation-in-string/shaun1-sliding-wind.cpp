//shaun's own idea, accepted 3rd sub
//cutting:  sliding window, expand right, contract left, valid window has all the chars in s1 and correct count
// 
//runtime 4ms, faster than 100%, mem less than 73%
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size(), len2 = s2.size();
        if (len > len2) return false;
        
        vector<int> m(26); //char in s1 and its count
        vector<int> wind(26); //sliding window, store char and its count
        for (char ch: s1) m[ch - 'a']++;
        
        for (int i = 0; i < len2; ++i) {
            if (i -len >=0) wind[s2[i-len]- 'a']--; //contract left
            wind[s2[i] - 'a']++; //expand right
            //if (isEqual(m, wind)) return true;
            if (m == wind) return true;
        }
        //no found
        return false;
    }
private:
    bool isEqual(vector<int>& m, vector<int>& window) {
        for (int i = 0; i < 26; i++)  {
            if (m[i] != window[i]) return false;
        }
        //all equal
        return true;
    }
};

