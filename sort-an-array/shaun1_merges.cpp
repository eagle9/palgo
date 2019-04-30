//shaun's own idea and code
//runtime 68ms, faster than 49%, mem less than 100%
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        if (nums.empty()) return {};
        int n = nums.size();
        vector<int> temp(n);
        mergeSort(nums,0,n-1,temp);
        return nums;
    }
private:
    //recursive merge sort A from left to right
    void mergeSort(vector<int>& A, int left, int right, vector<int>& temp) {
        if (left >= right) return;
        //left < right now
        int mid = left + (right-left)/2;
        mergeSort(A, left, mid, temp);
        mergeSort(A, mid+1, right, temp);
        merge2(A, left, mid, right, temp);
    }
    //merge 2 sorted array from left to mid,  mid+1 to right
    void merge2(vector<int>& A, int left, int mid, int right, vector<int>& temp ) {
        int i = left, j = mid+1;
        int k = left;
        while (i <= mid && j <= right) {
            if (A[i] < A[j]) {
                temp[k++] = A[i++];
            }else {
                temp[k++] = A[j++];
            }
        }
        if (i > mid) {
            while (j <= right) temp[k++] = A[j++];
        }else {
            while (i <= mid) temp[k++] = A[i++];
        }
        for (i = left; i <= right; ++i) A[i] = temp[i];
    }
};
