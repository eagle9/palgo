//shaun's own idea and code
//runtime 64ms, faster than 74.22%, mem less than 21%
//temp for merge2 only construct once, range [left,right), code is cleaner than [left,right] style
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        if (nums.empty()) return {};
        int n = nums.size();
        temp = vector<int>(n);
        mergeSort(nums,0,n);
        return nums;
    }
private:
    //recursive merge sort A [left,right)
    void mergeSort(vector<int>& A, int left, int right) {
        if (left+1 >= right) return;
        //left < right now
        int mid = left + (right-left)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge2(A, left, mid, right);
    }
    //merge 2 sorted array from [left,mid),  [mid to right)
    void merge2(vector<int>& A, int left, int mid, int right) {
        int i = left, j = mid;
        int k = left;
        while (i < mid && j < right) {
            if (A[i] < A[j]) {
                temp[k++] = A[i++];
            }else {
                temp[k++] = A[j++];
            }
        }
        
        while (j < right) temp[k++] = A[j++];
        while (i < mid)   temp[k++] = A[i++];
        for (i = left; i < right; ++i) A[i] = temp[i];
    }
private:
    vector<int> temp;
};

//shaun's own idea and code
//runtime 60ms, faster than 90.60%, mem less than 23%
//temp for merge2 only construct once, range [left,right]
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        if (nums.empty()) return {};
        int n = nums.size();
        temp = vector<int>(n);
        mergeSort(nums,0,n-1);
        return nums;
    }
private:
    //recursive merge sort A from left to right
    void mergeSort(vector<int>& A, int left, int right) {
        if (left >= right) return;
        //left < right now
        int mid = left + (right-left)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge2(A, left, mid, right);
    }
    //merge 2 sorted array from left to mid,  mid+1 to right
    void merge2(vector<int>& A, int left, int mid, int right) {
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
private:
    vector<int> temp;
};
