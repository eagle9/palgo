//jz idea and code, shaun understand and modified
//beats 0.2%
class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void min_heapify(vector<int> &A, int i, int len){  
        
        //   i
        //left   right
        
        int left = 2 * i + 1;  
        int right = 2 * i + 2;
        
        //find the min among i, left child, and right child
        int minIndex = i;  
        if( left < len && A[left] < A[i])  minIndex = left;
        if( right < len &&  A[right] < A[minIndex])  minIndex = right;

        if(minIndex != i) {
            swap(A[i], A[minIndex]);  
            min_heapify(A, minIndex, len);  
        }  
    }    
    void heapify(vector<int> &A) {
        // write your code here
        int len = A.size();
        for(int i = len / 2; i >= 0;i--)
            min_heapify(A, i, len);
    }
};

