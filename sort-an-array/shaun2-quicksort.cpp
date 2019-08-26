//shaun own from memory, self read and fixed on bug recursion with exit
//runtime 56ms, faster than 96%, mem less than 53%
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
        //return vector<int>(nums);
        
    }
    
private:
    void sort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        //left < right
        int ip = partition(nums, left, right);
        sort(nums, left, ip-1);
        sort(nums, ip+1, right);
    }
    //return pivot index such that left <   pi <=   right
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[i] < pivot ) i++;
            while (i < j && nums[j] >= pivot) j--;
            //nums[i] >=  pivot, nums[j] < pivot
            if (i < j) swap(nums[i], nums[j]);
        }
        
        //now i == j
        if (nums[i] < pivot) {
            swap(nums[i+1], nums[right]);
            return i+1;
        }
        //nums[i] >= pivot
        swap(nums[i], nums[right]);
        return i;
    }
};
