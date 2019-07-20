//grandyang idea, similar to valid palindrome ii
//3rd round accepted after fixing 4 bugs!!!!
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if (abs(len1 - len2) >= 2) return false;
        
        for (int i = 0; i < min(len1, len2); ++i) {
            if (s[i] != t[i]) {
                //case 1 try replace
                if (len1 == len2) {
                    //if (s.substr(i+1) == t.substr(i+1)) return true; --- bug 1, return always
                    return s.substr(i+1) == t.substr(i+1);
                }
                else if (len1 < len2) {
                    //case 2 try insert 1 char into s
                    //if (s.substr(i) == t.substr(i+1)) return true;
                    return s.substr(i) == t.substr(i+1);
                }else { //len1 > len2
                    //case 3 try delete 1 char from s
                    //if (s.substr(i+1) == t.substr(i)) return true;
                    return s.substr(i+1) == t.substr(i);
                }
                
            }
        }
        //no return true, means can not do 1 edit
        //return false; //---- bug
        //all equal before min(len1, len2)
        return abs(len1 - len2) == 1;
    }
};
