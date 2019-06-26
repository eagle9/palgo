//hua end_with dp idea with accumulate function
//runtime 8ms, faster than 67%, mem less than 64%
class Solution {
public:
    int distinctSubseqII(string S) {
        //constexpr int kMod = 1e9 + 7;
        const int kMod = 1e9 + 7;
        vector<int> end_with(26);
        for (char c : S) {
            //end_with[c - 'a'] = accumulate(begin(end_with), end(end_with), 1L) % kMod;
            end_with[c - 'a'] = accumulate(end_with.begin(), end_with.end(), 1L) % kMod;
        }
        return accumulate(begin(end_with), end(end_with), 0L) % kMod;
    }
};
