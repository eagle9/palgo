//https://blog.csdn.net/qq508618087/article/details/51320926
//shaun read, modified and understood some
//runtime 44ms, faster than 61.37%
//mem less than 12%
class Solution {
public:
    //for vp [left, right), sort and fill out ans
    void mergeSort(vector<pair<int, int>>& vp, int left, int right, vector<int> &ans){
        if(left+1 == right) return;//base case, why not fill ans?
        
        int mid = left+(right - left)/2;
        //vp[left, mid) sorted, fill out answer from low to mid)
        mergeSort(vp, left, mid, ans);
        //vp[mid, right) sorted, fill out answer from mid to high)
        mergeSort(vp, mid, right, ans); 
        
        //[low .... mid) sorted  [mid .... high) sorted, use this property to speed up
        //two pointers i: [left mid), j: [mid, right)
        int j = mid;
        for(int i = left; i < mid; i++){
            //vp[i].first ---  from mid, when right <, right++
            //or find number of element in [mid, right) that < vp[i].first
            while(j < right && vp[i].first > vp[j].first) j++;
            //vp[i].first's index?  vp[i].second
            ans[vp[i].second] += j-mid; //right-mid is the number that after vp[i] and <
        }
        inplace_merge(vp.begin()+left, vp.begin()+mid, vp.begin()+right);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0) return {};
        int len = nums.size();
        vector<int> ans(len, 0);
        vector<pair<int, int>> vp; //pair number with its original index
        //for(int i =0; i < len; i++) vec.push_back(make_pair(nums[i], i));
        for(int i =0; i < len; i++) vp.emplace_back(nums[i], i);
        mergeSort(vp, 0, len, ans);
        return ans;
    }
};
