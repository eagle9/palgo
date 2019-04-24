//shaun's own idea and code, accepted after fixing recursion exit condition
//beats 93% at lintcode
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        if (A.empty()) return;
        if (A.size() == 1) return;
        
        sort(A, 0, A.size()-1);
    }
    
    //recursion element 1: define 
    void sort(vector<int>& A, int left, int right) {
        if (left >=  right) return; //recursion element 2: exit
        
        int pivot = A[right];
        int i = partition(A, left, right-1, pivot);
        // < pivot       >= pivot
        //left -- i-1   i -- right
        swap(A[right], A[i]);
        //recursion element 3: recurrence
        sort(A, left, i-1);
        sort(A, i+1, right);
    }
    
    //return index of first e >= pivot
    int partition(vector<int> &A, int left, int right, int pivot){
        int i  = left, j = right;
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
    
};
