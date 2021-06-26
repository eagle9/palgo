class Solution {
    //nums range from 1 to nums.length-1
    //grandyang idea, shaun coded in java, beats 37%
    //T = nlogn
    public int findDuplicate(int[] nums) {
        int left = 0;
        int right = nums.length-1;  //nums.length okay too
        while (left < right) {
            int mid = left + (right-left)/2;
            int cnt = 0;
            for (int n: nums) {
                if (n <= mid) cnt++;
            }
            //1 2 ... mid ....nums.length-1
            //cnt <= mid means duplicated number is mid+1 -- right
            if (cnt <= mid) left = mid + 1;
            //otherwise cnt > mid, duplicated number is in 1... mid
            else right = mid;
        }
        //left == right
        //return right; okay
        return left; //okay too
        
    }
}

/*
//grandyang c++, beats 37%
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right){
            int mid = left + (right - left) / 2, cnt = 0;
            for (int num : nums) {
                if (num <= mid) ++cnt;
            }
            if (cnt <= mid) left = mid + 1;
            else right = mid;
        }    
        return right;
    }
};
*/
