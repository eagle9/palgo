//shaun and grandyang binary search ida
//runtime 12ms, faster than 97%, mem less than 77%
class Solution1 {
public:
    
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < A[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
//jz template
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size(), left = 0, right = n - 1;
        while (left+1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < A[mid + 1]) left = mid + 1;
            else right = mid;
        }
        if (A[left] < A[right]) return right;
        else return left;
    }
};
