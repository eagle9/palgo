#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*
     * @param k an integer
     * @param nums an integer array
     * @return kth smallest element
     */
    int kthSmallest(int k, vector<int>& nums) {
        // write your code here
        return helper(nums, 0, nums.size() - 1, k-1);
    }
private:
    int helper(vector<int>& nums, int start, int end, int index) {
        int p = partition(nums, start, end);
        if (p == index) {
            return nums[p];
        }
        else if (index > p) return helper(nums, p + 1, end, index);
        else return helper(nums, start, p - 1, index);
    }

    int partition(vector<int>&nums, int start, int end) {
        int pivot = nums[end];
        int i = start;
        for (int j = start; j < end; ++j) {
            if (nums[j] <= pivot) {
                swap(nums[i++], nums[j]);
            }
        }
        
        swap(nums[i], nums[end]);
        return i;
    }
};
int main() {
	vector<int> a = {3, 4, 1, 2, 5}; // k = 3, the 3rd smallest numbers are [1, 2, 3].
	for (int x: a) cout << x << " ";
	Solution s;
	int k = 3;
	int i = s.kthSmallest(k, a);
	cout << endl;
	cout << "i = " << i << " k=" << k << endl;
	for (int x: a) cout << x << " ";
	cout << endl;
}
