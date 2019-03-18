//shaun raw idea, 3rd version, accepted
//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
//turns out very clean and simple, easy to verify correctness
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums,nums.size());
    }
    //subset for the first n numbers
    //shaun's raw idea, 3rd try
    vector<vector<int>> helper(vector<int>& nums, int n) {
        if (n == 0) return {{}}; //0 numbers, {{}}
        vector<vector<int>> res;
        vector<vector<int>> left_set = helper(nums,n-1); 
        for (vector<int> left: left_set) {
            res.push_back(left); //nums[n-1] not used 
            vector<int> left2(left);
            left2.push_back(nums[n-1]);
            res.push_back(left2);
        }
        return res;
    }
};


//shaun's raw idea, without testing, not correct, duplicates
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums,nums.size());
    }
    //subset for n number from 0
    //shaun's raw idea, duplicate set
    vector<vector<int>> helper(vector<int>& nums, int n) {
        if (memo.count(n)) return memo[n];
        
        if (n == 0) return {{}}; //0 numbers, {{}}
        
        vector<vector<int>> res;
        //use nums[i] or not, all possible idx: 0 to end-1
        for (int i = 0; i < n; i++) {
            //0.. i-1   i   i+1 .. end-1 ---> end number
            // i-1 number i    end-i-1 numbers
            // i + 1 + end -1 - i = end 
            //left side i number, right side end-i-1
            vector<vector<int>> left_set = helper(nums, i);
            vector<vector<int>> right_set = helper(nums,n-i-1); //end -1 - (end-1)
            for (vector<int> left: left_set) {
                for (vector<int> right: right_set) {
                    inc(right,i+1);
                    
                    vector<int> v1(left.begin(),left.end());
                    v1.push_back(i);
                    v1.insert(v1.end(), right.begin(), right.end());
                    
                    vector<int> v2(left.begin(),left.end());
                    v2.insert(v2.end(),right.begin(), right.end());
                    
                    res.push_back(v1);
                    res.push_back(v2);
                    
                }
            }
        }
        return memo[n] = res;
        
    }
private:
    unordered_map<int,vector<vector<int>>> memo;
    void inc(vector<int>& right, int delta) {
        for (int i = 0; i < right.size(); ++i) 
            right[i] += delta;
    }
};

class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums,nums.size(),0);
    }
    //subset for n number from 0, wrong answer again
    //shaun's raw idea, duplicate set
    vector<vector<int>> helper(vector<int>& nums, int n, int start) {
        
        if (n == 0) return {{}}; //0 numbers, {{}}
        
        vector<vector<int>> res;
        //use nums[0] or not, 
         
            
        vector<vector<int>> right_set = helper(nums,n-1,start); //end -1 - (end-1)
            
        for (vector<int> right: right_set) {
            inc(right,start);
                    
            vector<int> v1;
            v1.push_back(nums[start]);
            v1.insert(v1.end(), right.begin(), right.end());
            
            res.push_back(v1); //used 
            res.push_back(right);
            
        }
        return res;
        
    }
private:
    unordered_map<int,vector<vector<int>>> memo;
    void inc(vector<int>& right, int delta) {
        for (int i = 0; i < right.size(); ++i) 
            right[i] += delta;
    }
};


/*
raw idea, kind of dumb copy of unique binary tree idea
for each i : nums
    //  0..i-1    i  i+1 .. n-1
    left_set = helper(i-1)
    right_set = helper(n-i-1)
    for (left: left_set)
        for (right: right_set)
            res.push_back(left + i + right) //use i
            res.push_back(left + right) //not use i
return res
*/
