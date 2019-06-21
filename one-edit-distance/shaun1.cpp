//shaun's own idea, first sub wrong answer, failing case s=a, t=ab
//tried different own idea upon seeing the failing case
// further fixed 1 bug, finally accepted
//runtime 20ms, faster than 7%, mem less than 5%

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (abs(m - n) >= 2) return false;
        if (m == n) {
            //diff only 1 char, return true, else false
            int count = 0;
            for (int i = 0; i < m; ++i) {
                if (s[i] != t[i]) count++;
                if (count > 1) return false;
            }
            return count  == 1;
        }
        //m = n - 1
        if (m < n) {
            return helper(s,t);
        }else {
            return helper(t,s);
        }
    }
private:
    
    //to do make it faster
    bool helper2(string s, string t) {
        int n = t.length();
        if (s == t.substr(1) || s == t.substr(0,n-1)) return true;
        int i= 0, j = 0;
        bool foundDiff = false;
        while ( j < n) {
            if (s[i] != t[j]) {
                if (foundDiff)
                j++;
                foundDiff = true;
            }else {
                i++; j++;
            }
        }
    }
    
    //s.length() +1  = t.length()
    //accepted after 1 bug fix
    //runtime 8ms, faster than 27%, mem less than 5%
    bool helper(string s, string t) {
        int n = t.length();
        for (int i = 0; i < n; ++i) {
            //0 i-1  i  i+1
            string t2 = i+1 == n? "": t.substr(i+1);
            string t1 = t.substr(0,i);
            //string t1 = i-1>0? t.substr(0,i-1): ""; // --- bug, check length
            if (t1 + t2 == s) return true;
        }
        return false;
    }
    
    //s.length +1 == t.length
    //wrong answer
    bool helper000(string s, string t) {
        int i,j = 0;
        int count = 0;
        while (i < s.size() && j < t.size()) {
            cout << s[i] << "," << s[j] << endl;
            if (s[i] != t[j]) {
                count++;
                j++;
                if (count > 1) return false;
                
            }
            else {
                i++; j++;
            }
        }
        return count == 1;
    }
};

