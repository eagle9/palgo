
//shaun's own idea learned from lt offical quickselect
//fixing several typo and loose dealing with details
//finally accepted, runtime 12ms, faster than 97%, mem less than 55%
//the key is change kth to index(sorted) and just see if we can get partition index that is equal
class Solution {
    int findKthLargest(int [] nums, int k) {
        
        int size = nums.length;
        //1   2   ....   n-1  n
        //               2    1   1st largest sorted index = size-1, kth largest sorted index = size-k
        
        //return quickSelect(nums, size-k, 0, size);  //AddressSanitizer
        return quickSelect(nums, size-k, 0, size-1);
    }
    
    //define recursion: return  nums[sindex] such that if nums sorted ascending,
    //  the sindex-th ranked(smaller higher rank) element
    int quickSelect(int [] nums, int sindex, int left, int right) {
        //recursion exit? 
        if (left == right) return nums[left];
        int p = partition(nums, left, right);
        
        // bug earlier if sindex = p
        //kth largest index == pivot index
        if (sindex == p) return nums[p];
        
        //now sindex != p
        //[left, p] range covers sindex, look in left, p-1 range
        else if (sindex < p) return quickSelect(nums, sindex, left, p-1);
        //[p,right] range covers sindex, look in [p+1, right range]
        else return quickSelect(nums, sindex, p+1, right);
    }
    
    int partition(int [] nums, int left, int right) {
        int ipv = left + (new Random()).nextInt(right-left+1); //pick a random index from left to right
        int pivot = nums[ipv];
        //swap(nums[ipv], right); //place to pivot at right
        swap(nums, ipv, right);
        int i = left, j = right;
        // smaller to left, greater to right
        while (i < j) {
            while (nums[i] < pivot && i < j) i++;
            while (nums[j] >= pivot && i < j) j--;
            if (i < j) {
                //ni >= pivot && nj < pivot
                swap(nums, i++, j--);
            }
        }
        //i == j now, 1 number left unchecked
        if (nums[i] >= pivot) {
            swap(nums, i, right); //place pivot at final pivot index
            return i;
        }
        //ni < pivot, put pivot to i+1
        swap(nums, i+1, right);
        return i+1;
    }
    void swap(int []a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
        
};

