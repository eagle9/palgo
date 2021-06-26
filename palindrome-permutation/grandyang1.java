class Solution {
    //grandyang idea 1, shaun coded in java, beats 67%
    public boolean canPermutePalindrome(String s) {
        Map<Character,Integer> m = new HashMap<>();
        int cnt = 0;
        for (char c: s.toCharArray()) {
            if (!m.containsKey(c)) m.put(c,1);
            else m.put(c, m.get(c) + 1);
        }
        
        for (char c: m.keySet()) {
            //odd frequency char count
            if (m.get(c) % 2 == 1) cnt++;
        }
        //only care about odd frequency chars
        if (cnt ==0) return true;
        if (cnt == 1 && s.length() % 2 == 1) return true;
        return false;
    }
}


/*
//grandyang c++ v1, beats 100%
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int cnt = 0;
        for (auto a : s) ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2) ++cnt;
        }
        return cnt == 0 || (s.size() % 2 == 1 && cnt == 1);
    }
};
*/
