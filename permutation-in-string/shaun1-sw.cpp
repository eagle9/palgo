//shaun's own idea, accepted 3rd sub
//runtime 4ms, faster than 100%, mem less than 73%
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size(), len2 = s2.size();
        if (len > len2) return false;
        
        vector<int> m(26), wind(26);
        for (char ch: s1) m[ch - 'a']++;
        
        
        for (int i = 0; i < len; ++i) wind[s2[i] - 'a']++;
        if (isEqual(m, wind)) return true;
        for (int i = len; i < len2; ++i) {
            wind[s2[i-len]- 'a']--;
            wind[s2[i] - 'a']++;
            if (isEqual(m, wind)) return true;
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
