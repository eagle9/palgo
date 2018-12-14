//grandyang c++, beats 99%
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //c++ init array only one [], java use two: int [] a = new int[n]
        int map1[256] = {0}, map2[256] = {0}, n = s.size();
        //c++ string.size, java String.length()
        for (int i = 0; i < n; ++i) {
            //c++ string[i] , java String.charAt
            if (map1[s[i]] != map2[t[i]]) return false;
            map1[s[i]] = i + 1;
            map2[t[i]] = i + 1;
        }
        return true;
    }
};
