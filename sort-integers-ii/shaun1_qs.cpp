//shaun's own idea and code, accepted after fixing recursion exit condition
//beats 93% at lintcode
//shaun's own idea and code, accepted after fixing recursion exit condition
//initially pick A[right] as pivot, later, pick random as pivot, get familiar with c++ random for a range and deal with pivot
//runtime 64ms, faster than 95%, mem less than 100%
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
        if (left >= right) return; //recursion element 2: exit
        //use right as pivot, or pick a random, place the pivot at right
        int ip = left + rand()%(right-left+1);
        swap(A[ip], A[right]);
        
        //int ip = right;
        
        int pivot = A[right];
        int i = partition(A, left, right-1, pivot);
        // < pivot       >= pivot
        //left -- i-1   i -- right
        //recursion element 3: recurrence
        swap(A[right], A[i]);
        sort(A, left, i-1);
        sort(A, i+1, right);
    }
    
    //return index of first e >= pivot
    int partition(vector<int> &A, int i, int j, int pivot){
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

