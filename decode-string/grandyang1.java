//grangyang recursion idea, 3ms beats 95%
class Solution {
    private int i = 0;
    public String decodeString(String s) {
        return decode(s).toString();
    }
    private StringBuilder decode(String s) {
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        while ( i < n && s.charAt(i) != ']') {
            if (s.charAt(i) < '0' || s.charAt(i) > '9') {
                sb.append(s.charAt(i++));
            }else { //is digit
                int cnt = 0;
                while (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    cnt = cnt * 10 + (s.charAt(i++) - '0');
                }
                ++i;
                StringBuilder t = decode(s);
                ++i;
                while (cnt-- > 0) {
                    sb.append(t);
                }
            }
        }
        return sb;
    }
}

/*
//grandyang idea1 recursion, 0ms beats 100%
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    string decode(string s, int& i) {
        string res = "";
        int n = s.size();
        while (i < n && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                res += s[i++];
            } else {
                int cnt = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + s[i++] - '0';
                }
                ++i;
                string t = decode(s, i);
                ++i;
                while (cnt-- > 0) {
                    res += t;
                }
            }
        }
        return res;
    }
};
*/
