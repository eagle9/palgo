//grandyang --- http://www.cnblogs.com/grandyang/p/5184698.html
//shaun modified for better read
//Your submission beats 94.60% Submissions!
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        if (abs(n-m) > 1) return false;
        for (int i = 0; i < min(n,m); ++i) {
            if (s[i] != t[i]) {
                //equal length, after i must all match
                if (n == m) return s.substr(i + 1) == t.substr(i + 1);
                //s 1 fewer char,   then s[i..] == t[i+1..]
                else if (n < m) return s.substr(i) == t.substr(i + 1);
                //t 1 fewer char, 
                else return  t.substr(i) == s.substr(i + 1);
            }
        }
        //now for loop exit and match all, m and n must diff by 1, otherwise false
        return abs(n-m) == 1;
    }
};
