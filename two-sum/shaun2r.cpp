/*
shaun first try, wrong answer, fixed condition with m[k] != i
c++ check if key is in umap,  umap.find() or umap.count()
Runtime: 12 ms, faster than 94.91% of C++ online submissions for Two Sum.
*/
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; //number to its index
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            m[nums[i]] = i;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int k = target - nums[i];
            
            if (m.count(k) && m[k] != i)  { //found k
                res.push_back(i);
                res.push_back(m[k]);
                return res;
            }
        }
        return res;
    }
};

//one pass, 12ms, faster than 95%
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; //number to its index
        int n = nums.size();
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int k = target - nums[i];
            
            if (m.count(k) && m[k] != i)  { //found k
                res.push_back(i);
                res.push_back(m[k]);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};

//use sorting, two pointers and pair, runtime 12ms, faster than 95%
//use pair to remember original position
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            vp.push_back(make_pair(nums[i],i));
        }
        sort(vp.begin(), vp.end());
        
        vector<int> res;
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = vp[left].first + vp[right].first;
            if ( sum == target) {
               res.push_back(vp[left].second);
               res.push_back(vp[right].second);
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
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<ni> vp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            vp.push_back(ni{nums[i],i});
        }
        //sort(vp.begin(), vp.end());
        sort(vp.begin(), vp.end(), niCompare());
        
        vector<int> res;
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = vp[left].num + vp[right].num;
            if ( sum == target) {
               res.push_back(vp[left].pos);
               res.push_back(vp[right].pos);
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
