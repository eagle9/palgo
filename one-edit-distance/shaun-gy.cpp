//grandyang cutting angle, how to deal with difference, use substr
//runtime 4ms, faster than 94%, mem less than 8%
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (abs(m-n) > 1) return false;
        
        for (int i = 0; i < min(m,n); i++) {
            //how to deal with difference
            if (s[i] != t[i]) {
                if (m == n) return s.substr(i+1) == t.substr(i+1); //replace 1 char
                if (m < n) return s.substr(i) == t.substr(i+1); // delete 1 char from longer string
                else return t.substr(i) == s.substr(i+1); 
            }
        }
        
        //all equal befor min(m,n)
        return abs(m-n) == 1;
    }
};
