//shaun's own idea learned from lt offical quickselect
//fixing several typo and loose dealing with details
//finally accepted, runtime 12ms, faster than 97%, mem less than 55%
//the key is change kth to index(sorted) and just see if we can get partition index that is equal
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int size = nums.size();
        //1   2   ....   n-1  n
        //               2    1   1st largest sorted index = size-1, kth largest sorted index = size-k
        
        //return quickSelect(nums, size-k, 0, size);  //AddressSanitizer
        return quickSelect(nums, size-k, 0, size-1);
    }
    
    //define recursion: return  nums[sindex] such that <sindex, < nums[sindex]
    //   > sindex, >= nums[sindex]
    int quickSelect(vector<int>& nums, int sindex, int left, int right) {
        //recursion exit? 
        if (left == right) return nums[left];
        int p = partition(nums, left, right);
        //if (sindex = p) return nums[p];
        if (sindex == p) return nums[p];
        else if (sindex < p) return quickSelect(nums, sindex, left, p-1);
        else return quickSelect(nums, sindex, p+1, right);
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int ipv = left + rand()%(right-left+1); //pick a random index from left to right
        int pivot = nums[ipv];
        //swap(nums[ipv], right); //place to pivot at right
        swap(nums[ipv], nums[right]);
        int i = left, j = right;
        while (i < j) {
            while (nums[i] < pivot && i < j) i++;
            while (nums[j] >= pivot && i < j) j--;
            if (i < j) {
                //ni >= pivot && nj < pivot
                swap(nums[i++], nums[j--]);
            }
        }
        //i == j now
        if (nums[i] >= pivot) {
            swap(nums[i], nums[right]); //place pivot at final pivot index
            return i;
        }
        swap(nums[i+1], nums[right]);
        return i+1;
    }
};
