//solution no.4, runtime 8ms, faster than 100%
struct ni {
    int num;
    int pos;
    /*
    bool operator<(const ni& other) const {
        return num < other.num; //order from small to big
    }*/
};
struct niCompare {
    bool operator()(const ni& a, const ni& b) const{
        return a.num < b.num;
    }
};
//use 2 pointers with customized struct to keep original index
//runtime 8ms, faster than 99.9%, mem less than 59%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<ni> vp(n);
        
        for (int i = 0; i < n; ++i) {
            vp[i] = ni({nums[i],i});
        }
        //sort(vp.begin(), vp.end());
        sort(vp.begin(), vp.end(), niCompare());
        
        vector<int> res(2);
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = vp[left].num + vp[right].num;
            if ( sum == target) {
               res[0] = vp[left].pos;
               res[1] = vp[right].pos;
               return res;
            }else if (sum < target) {
                ++left;
            }else {
                --right;
            }
        }
        return res;
    }
};
