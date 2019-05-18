//shaun's own idea and code, accepted second sub
//runtime 4ms, faster than 100%, mem less than 86%
class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x^y;
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += val & 1;
            val >>= 1;
        }
        return count;
    }
};
