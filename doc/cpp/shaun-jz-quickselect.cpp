//shaun modified jz quickselect, partition left > pivot > right, to align better
//                                          0      k-1 --->kth largest
//runtime 28ms, faster than 33%, mem less than 84%
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    
private:
    //  1      k ------> bingo               
    // 0 >   pivot >    len-1 
    //     k    ---  left to pivot-1
    //             k ---->  pivot+1 to right
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left <= right) {
            int p = partion(nums, left, right);
            if (p ==  k-1)
                return nums[p];
            
            else if (p >  k-1)
                return quickSelect(nums, left, p - 1, k);
            else
                return quickSelect(nums, p + 1, right, k);
        }
        return -1;
    }
    
    int partion(vector<int>& nums, int left, int right) {
        //take left as pivot index
        int i = left + 1, j = right;
        while (i <= j) {
            while (i <= right && nums[i] > nums[left]) i++;
            while (j >= left + 1 && nums[j] < nums[left]) j--;
            //if (i > j) break;  for while true
            if (i <= j) swap(nums[i++], nums[j--]);
        }
        swap(nums[left], nums[j]);
        return j;
    }
};

