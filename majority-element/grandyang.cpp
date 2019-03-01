//grandyang idea1, runtime 20ms, faster than 99.60%
//to understand
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {res = num; ++cnt;}
            else (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};

//grandyang idea2, runtime 24ms, faster than 57%
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if (ones > n / 2 || zeros > n / 2) break;
                if ((num & (1 << i)) != 0) ++ones;
                else ++zeros;
            }
            if (ones > zeros) res |= (1 << i);
        }
        return res;
    }
};
