//reverse direction two pointers jz, shaun code from the idea, accepted after debugging
//beats 72% submissions
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        int n = nums.size();
        
        int left = 0, right = n-1;
        while (left < right) {
            while (nums[left] < k && left < right) left++; 
            while (nums[right] >= k && left < right) right--;
            if (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        // right == left now, linhuchong treatment, pretty smart
        if (nums[left] < k) return left+1;
        else return left;
    }
    int partition(vector<int> &nums, int left, int right, int pivot) {
		if (left >= right) return left;
        
        while (left < right) {
            while (nums[left] < pivot && left < right) left++; 
            while (nums[right] >= pivot && left < right) right--;
            if (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        // right == left now, linhuchong treatment, pretty smart
        if (nums[left] < pivot) return left+1;
        else return left;
    }
	//return index of first e >= pivot, used in leetcode sort an array
    int partition2(vector<int> &A, int i, int j, int pivot){
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
int main() {
	vector<int> a = {1 ,4,3, 10, 14,12};
	for (int x: a) cout << x << " ";
	cout << endl;
	Solution s;
	int pivot = 10;
	cout << "pivot=" << pivot << endl;
	//return index of the first e >= pivot
	int res = s.partition2(a,0,a.size(),pivot);
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "first index >= pivot is " << res << endl;
}
