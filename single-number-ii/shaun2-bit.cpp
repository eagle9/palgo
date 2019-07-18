//shaun own idea after 2 month memory, accepted first sub
//runtime 12ms, faster than 79%, mem less than 26%
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32); //count of set bit from 0 to 31
        
        for (int num: nums) {
            for (int i = 0; i < 32; i++) {
                int b = (num >> i) & 1;
                count[i] += b;
                if (count[i] > 0 && count[i] % 3 == 0) count[i] = 0;
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i]) res = res | (1 << i);
        }
        return res;
    }
};
