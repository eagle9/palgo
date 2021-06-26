/*
Runtime: 156 ms, faster than 47.92% of C++ online submissions for Random Pick Index.
Memory Usage: 36.5 MB, less than 10.00% of C++ online submissions for Random Pick Index.

gy reservoir sampling
这道题指明了我们不能用太多的空间，那么省空间的随机方法只有水塘抽样Reservoir Sampling了，LeetCode之前有过两道需要用这种方法的题目Shuffle an Array和Linked List Random Node。那么如果了解了水塘抽样，这道题就不算一道难题了，我们定义两个变量，计数器cnt和返回结果res，我们遍历整个数组，如果数组的值不等于target，直接跳过；如果等于target，计数器加1，然后我们在[0,cnt)范围内随机生成一个数字，如果这个数字是0，我们将res赋值为i即可
*/
class Solution {
public:
    Solution(vector<int> nums): v(nums) {}
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) continue;
            ++cnt;
            if (rand() % cnt == 0) res = i;
        }
        return res;
    }
private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
