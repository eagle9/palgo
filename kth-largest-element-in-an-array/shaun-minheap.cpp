//kth largest, use a minheap to keep the larger elements, min element at top to be removed
//control the heap size
//shaun own idea, accepted after 1 bug fix
//runtime 8ms, faster than 98%, mem less than 34%, 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //note c++ pq by default is reverse of natural order ---- bug can not use default pq<int>
        priority_queue<int,vector<int>, greater<int>> minheap;
        int n = nums.size();
        //assume k < n
        for (int i = 0; i < n; ++i) {
            minheap.push(nums[i]);
            if (minheap.size() > k) {
                minheap.pop();
            }
        }
        return minheap.top();
    }
};
