class Solution {
    //grandyang idea using set, beats 67%
    public boolean canPermutePalindrome(String s) {
        Set<Character> t = new HashSet<>();
        int len = s.length();
        for (int i =0; i< len; i++ ) {
            char c = s.charAt(i);
            if (!t.contains(c)) t.add(c);
            else t.remove(c);
        }
        return t.isEmpty() || t.size() == 1;
    }
}

/*
//grandyang c++ using set, beats 100%
class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> t;
        for (auto a : s) {
            if (t.find(a) == t.end()) t.insert(a);
            else t.erase(a);
        }
        return t.empty() || t.size() == 1;
    }
};


*/
