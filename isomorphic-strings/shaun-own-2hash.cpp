
/*shaun's idea, only use map1, wrong answer, was not to the point of 1on1 mapping
user map1 and map2, beats 16%
key is 1 to 1 mapping, using 1 map won't cut it
key point2, key are chars, you can use array rather than full blown hashmap
runtime 12ms, faster than 56%, mem less than 55%
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1, m2;
        //vector<char> m1(256), m2(256);
        if (s.length() != t.length()) return false;
        
        for (int i = 0; i < t.length(); ++i) {
            if (m1.count(s[i])) {
                if (m1[s[i]] != t[i]) return false;
            }else {
                m1[s[i]] = t[i];
            }
                
            if (m2.count(t[i])) {
                if (m2[t[i]] != s[i]) return false;
            }else {
                m2[t[i]] = s[i];
            }
        }
        //pass all tests
        return true;
    }
};


