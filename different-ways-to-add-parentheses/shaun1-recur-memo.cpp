// hua idea with recursion with memo, shaun read and understand
//runtime 0ms, faster than 100%, mem less than 73%

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return ways(input);
    }
private:    
    
    vector<int> ways(const string& input) {
        // Already solved, return the answer
        if(m_.count(input)) return m_[input];
        
        // Array for answer of input
        vector<int> ans;
        
        // Break the expression at every operator
        for(int i=0;i<input.length();++i) {
            char op = input[i];
            // Split the input by an op
            if(op=='+' || op=='-' || op=='*') {
                const string left = input.substr(0, i); //0 to i-1, len i
                const string right = input.substr(i+1); //i+1 to end
                // Get the solution of left/right sub-expressions
                const vector<int>& l = ways(left);
                const vector<int>& r = ways(right);
                
                // Combine the solution
                for(int a : l) {
                    for(int b : r) {
                        int res = 0;
                        switch (op) {
                            case '+': res = a + b; break;
                            case '-': res = a - b; break;
                            case '*': res = a * b; break;
                        }
                        ans.push_back(res);
                    }
                }
            }
        }
        
        // Single number, e.g. s = "3", no operator found inside input
        if(ans.empty()) ans.push_back(stoi(input));
        
        // memorize the answer for input
        return m_[input] = ans;
        
    }
    
    unordered_map<string, vector<int>> m_;
};
