//https://kingsfish.github.io/2017/12/15/Leetcode-421-Maximum-XOR-of-Two-Numbers-in-an-Array/#cheat-solution
//用上一个异或的特性，假设a和b产生了最终的答案max，即a ^ b = x，那么根据异或的特性，a ^ x = b。同理，a和b的最高位（前n位）也有相同的性质。

//runtime 116ms, faster than 52%, mem less than 27%
class Solution {
public:
    int findMaximumXOR(vector<int> nums) {
        int max = 0;
        int mask = 0;
        for(int i = 31; i >= 0; i --){
            // 为获取前n位的临时变量
            mask = mask | (1 << i);
            unordered_set<int> set;
            for(int num : nums){
            // 将所有数字的前n位放入set中
                set.insert(mask & num);
            }
            // 假定第n位为1,前n-1位max为之前迭代求得
            int a = max | (1 << i);
            for(int x : set){
                // 查看`b`是否在
                if(set.count(a ^ x)){ 
                // b存在，第n位为1
                    max = a;
                    break;
                }
            }                    
        }
        return max;
    }
};
