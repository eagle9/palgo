//shaun's own idea and code, accepted after fixing recursion exit condition
//runtime 64ms, faster than 95%, mem less than 100%
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }

    //recursion element 1: define
    void sort(vector<int>& A, int left, int right) {
        if (left >= right) return; //recursion element 2: exit
        //int ip = left + rand()%(right-left+1);
        //swap(A[ip], A[right]);
        
        //int ip = right;
        
        //int pivot = A[ip];
        //int p = partition1(A, left, right-1, pivot);
        //swap(A[ip], A[p]);
        
        int p = partition2(A,left, right);
        // < pivot       >= pivot
        //left -- p-1   p -- right
        //recursion element 3: recurrence
        
        sort(A, left, p-1);
        sort(A, p+1, right);
    }
    
    //return index of first e >= pivot
    int partition1(vector<int> &A, int i, int j, int pivot){
        while (i < j) {
            while (A[i] < pivot && i < j ) i++;
            while (A[j] >= pivot && i < j) j--;
            if (i < j) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
        //i == j now
        if (A[i] < pivot) return i+1;
        else return i; //Ai >= pivot
    }
    
    int partition2(vector<int>& nums, int start, int end) {
        int ipv = start + rand()%(end-start+1);
        int pivot = nums[ipv];
        swap(nums[ipv], nums[end]);
        
        int left = start, right = end;
        while (left < right) {
            while (nums[left] < pivot && left < right) {
                left++;
            }
            while (nums[right] >= pivot && right > left) {
                right--;
            }
            if (left < right) swap(nums[left], nums[right]);
        }
        //left == right
        if (nums[left] >= pivot) {
            swap(nums[left], nums[end]);
            return left;
        }else {
            swap(nums[left+1], nums[end]);
            return left+1;
        }
    }
    
};

