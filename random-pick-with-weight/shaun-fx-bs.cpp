//runtime 136, faster than 94%, mem less than 90%
//gy idea, but fuxue has the best explanation, i can understand, but not very easy to come up with such a clever and rare practised solution
/*
这个题很巧妙，我是想不出来的。做法是把概率分布函数转化为累计概率分布函数。然后通过随机数，进行二分查找。
比如，输入是[1,2,3,4]，那么概率分布是[1/10, 2/10, 3/10, 4/10, 5/10]，累积概率分布是[1/10, 3/10, 6/10, 10/10].总和是10。如果我们产生一个随机数，在1~10之中，然后判断这个数字在哪个区间中就能得到对应的索引。
pick 1 with 1/10
pick 2 with 2/10
pick 3 with 3/10
pick 4 with 4/10
[1 2 2 333 4444]
[1 2 3 456 789x] random number x 1 to 10
 0 1 2 3 
[1 3 6 10]  random x = 0 to 9, 
   x = 0, first > x, first idx is 0, return 0
   x = 1, first > x, first idx is 1, return 1
   x = 2, first > x, first idx is 1, return 1
   x = 3, first > x, first idx is 2, return 2
   x = 4, first > x, first idx is 2, return 2
   x = 5,                            return 2, 
   x = 6             first idx is 3, return 3
   x = 7
   x = 8
   x = 9

相当于找比s大的preSum值的索引。
来源：CSDN 
原文：https://blog.csdn.net/fuxuemingzhu/article/details/81807215 

*/
class Solution {
public:
    Solution(vector<int> w) {
        //gsum = w;
        sum = vector<int>(w.size());
        sum[0] = w[0]; 
        for (int i = 1; i < w.size(); ++i) {
            sum[i] = sum[i - 1] + w[i];
        }
    }
    
    //use binary search to find the first index whose value > target
    //  while num[mid] > target, keep going to lower half: right = mid
    int pickIndex() {
        int target = rand() % sum.back(), left = 0, right = sum.size() - 1;
        //first > 
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= target) left = mid + 1;
            else right = mid; // sum[mid] > target, first half
        }
        //left == right
        return right;  //sum[right] > target and be the first
    }
    
private:
    vector<int> sum;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
