//shaun's own idea and code, two pointer template kind of, 
//beats 72% subs at lintcode
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
	//elements < k in front, elements >=k in the back
	//return index of first element >=k
	//0 -- res-1     res--  len-1
    int partitionArray(vector<int> &nums, int k) {
        int i = 0; //index that stores elements < k
        for (int j = 0; j < nums.size(); ++j) {
        	if (nums[j] < k) {
        		int temp = nums[i];
        		nums[i] = nums[j];
        		nums[j] = temp;
        		i++;
        	}
        }
        return i;
    }
    int partition(vector<int> &nums, int left, int right, int pivot) {
        int i = left; //index that stores elements < k
        for (int j = left; j <= right; ++j) {
        	if (nums[j] < pivot) {
        		int temp = nums[i];
        		nums[i] = nums[j];
        		nums[j] = temp;
        		i++;
        	}
        }
        return i;
    }
};
int main() {
	vector<int> a = { 1, 2,4,3, 10, 11, 14,12};
	for (int x: a) cout << x << " ";
	cout << endl;
	Solution s;
	int pivot = 10;
	cout << "pivot=" << pivot << endl;
	//return index of the first e >= pivot
	int res = s.partition(a,0,a.size(),pivot);
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "first index >= pivot is " << res << endl;
}
