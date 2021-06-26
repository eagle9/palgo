//time nlogn divide and conquer, lt modified merge sort, not easy to come up the idea
//understand most of it, why sort? changing order still correct???
//runtime 220ms, faster than 78%, mem less than 86%
class Solution {
public:
    
    //lt merge
    void merge2(vector<int>& A, int start, int mid, int end){
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = A[start + i];
        for (int j = 0; j < n2; j++)
            R[j] = A[mid + 1 + j];
        int i = 0, j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j]))
                A[k] = L[i++];
            else
                A[k] = R[j++];
        }
    }
    //jz merge 
    void merge(vector<int>& A, int start, int mid, int end) {
        int i = start, j = mid + 1, k = 0;
        vector<int> tmp(end - start+1); //bug tmp(A.size())
        while (i <= mid && j <= end) {
            if (A[i] > A[j]) {
                tmp[k++] = A[j++];
                
            } else {
                tmp[k++] = A[i++];
            }
        }
        //done with i or j
        while (i <= mid) tmp[k++] = A[i++];
        while (j <= end) tmp[k++] = A[j++];
        for (i = start;i <= end; ++i)
            A[i] = tmp[i-start];
    }

    int mergesort_and_count(vector<int>& A, int start, int end){
        if (start < end) {
            int mid = (start + end) / 2;
            int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
            int j = mid + 1;
            //start ... mid  mid+1 ... end
            for (int i = start; i <= mid; i++) {
                //A[j] is sorted increasing, that's why we can do this quick j++ count, once A[j]*2 >= 
                //once A[j] * 2 >= A[i]
                while (j <= end && A[j]*2LL  < A[i]) //LL is suffix for long long, 64 bit literal
                    j++;
                count += j - (mid + 1); //
                /*  TLE
                for (int j = mid+1; j <= end; ++j) {
                    if (A[i] > A[j] * 2LL) {
                        count++;
                    }
                }*/
            }
            merge(A, start, mid, end);
            return count;
        }
        else
            return 0;
    }

    int reversePairs(vector<int>& nums){
        return mergesort_and_count(nums, 0, nums.size() - 1);
    }
};
