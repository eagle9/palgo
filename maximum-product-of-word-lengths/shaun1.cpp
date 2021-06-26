//grandyang idea, shaun has read and understand
//runtime 48ms, faster than 94%, mem less than 71%
//lower case letter a-z, 26 letter, 32bits enough
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> mask(words.size(), 0); //each word sets bits by its letters
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            //for any pair i and j
            for (int j = 0; j < i; ++j) {
                if (!(mask[i] & mask[j])) { //no same letter
                    //string.size() return size_t type
                    res = max(res, (int)(words[i].size() * words[j].size()));
                    //res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
