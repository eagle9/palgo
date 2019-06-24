//grandyang idea2, dfs, similar to lt idea, cleaner code
//shaun has read and understood well

//runtime 12ms, faster than 81%, mem less than 79%
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> a(nums.begin(), nums.end()); //int vector to double vector
        return helper(a);
    }
    bool helper(vector<double>& nums) {
        //recursion exit base cases
        if (nums.empty()) return false; //no number in nums, return false
        if (nums.size() == 1) return abs(nums[0] - 24) < epsilon;
        
        //choose any two numbers out of nums
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                
                //create another vector<double>, without i and j
                vector<double> t;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) t.push_back(nums[k]);
                }
                //apply op to i and j, 2 number to 1 number
                for (char op : ops) {
                    if ((op == '+' || op == '*') && i > j) continue; //skip repetition i+j j+i i*j j*i, you can comment this, still works, but slower
                    //if (op == '/' && nums[j] < epsilon) continue; //skip division by 0
                    if (op == '/' && nums[j] == 0) continue; //skip division by 0
                    switch(op) {
                        case '+': t.push_back(nums[i] + nums[j]); break;
                        case '-': t.push_back(nums[i] - nums[j]); break;
                        case '*': t.push_back(nums[i] * nums[j]); break;
                        case '/': t.push_back(nums[i] / nums[j]); break;
                    }
                    //t is 1 smaller than nums, recursively solve the smaller problem
                    if (helper(t)) return true;
                    
                    t.pop_back(); //backtracking, try next i&j
                }
            }
        }
        //no 24 found, now return false
        return false;
    }
private:
    double epsilon = 0.000001;
    vector<char> ops{'+', '-', '*', '/'};
    
};
