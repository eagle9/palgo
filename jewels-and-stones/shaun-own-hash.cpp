//shaun own idea and code, accepted first sub
//runtime 0ms, faster than 100%, mem less than 44%
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels(J.begin(), J.end());
        int cnt = 0;
        for (char ch: S) {
            if (jewels.find(ch) != jewels.end()) cnt++;
        }
        return cnt;
    }
};
