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
            int p = partition1(nums, left, right);
            //int p = partition1(nums, left, right);
			//   0 -- k-2 p ... ---> k-1 numbers > nums[p]
            if (p ==  k-1)
                return nums[p];
            
            else if (p >  k-1)
                return quickSelect(nums, left, p - 1, k);
            else
                return quickSelect(nums, p + 1, right, k);
        }
        return -1;
    }
    
    //not very clear about this partition scheme
    //works, runtime 32ms, faster than 26%, mem less than 6%
	//dec 22 2019 dodge ridge understood - return pivot index such that
	//   >pivot pivot <= pivot
    int partition(vector<int>& nums, int left, int right) {
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
    
    //hoare's partition
    //runtime 8ms, faster than 98%, mem less than 36%
    //partion used in quick sort, slight updated  
    // instead of [ <pivot  pivot >=pivot]
    // [ >pivot  pivot  <= pivot]
    int partition1(vector<int>& nums, int start, int end) {
        //int ipv = start + rand()%(end-start+1);
        int ipv = start + (end - start)/2;
        int pivot = nums[ipv];
        swap(nums[ipv], nums[end]);
        
        int i = start, j = end;
        while (i < j) {
            while (nums[i] > pivot && i < j) i++;
            while (nums[j] <= pivot && i < j) j--;
            
            if (i < j) swap(nums[i], nums[j]);
        }
        // start i==j ... end-1   end
        //   >p   nums[i]  <=p    pivot
        //  >p   pivot     <=p    nums[i]<=p
        //  >p   num[i]  i+1  <=p    end
        if (nums[i] <= nums[end]) {  // nums[i] put after pivot
            swap(nums[i], nums[end]);  
            return i;
        }else { //nums[i] > pivot
            swap(nums[i+1], nums[end]);
            return i+1;
        }
    }
};

