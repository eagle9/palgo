//grandyang recursion, match s with p, from start, 1 char, the shorter string 
//not fully understand * case
//runtime 192ms, faster than 25%, mem less than 26%
class Solution {
public:
    bool isMatch(string s, string p) {
        //empty pattern
        if (p.empty()) return s.empty();
        
        //single char pattern
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        
        //now pattern 2 or more chars
        //p[1] not *
        if (p[1] != '*') {
            if (s.empty()) return false;
            
            //first char ==, or p[0] == '.'', boils now 
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        
        //p[1] == *
        /*s = "aab" p = "c*a*b" return true
             aab, a*b  s p2 no match
             ab b
        s = "ab" p = ".*" return  true
        */
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};
