// hua idea with recursion with memo
//runtime 4ms, faster than 98%, mem less than 94%
namespace huahua {
    int add(int a, int b) { return a+b; }
    int minus(int a, int b) { return a-b; }
    int multiply(int a, int b) { return a*b; }
} // namespace huahua
 
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return ways(input);
    }
private:    
    
    const vector<int>& ways(const string& input) {
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
                
                //std::function<int(int,int)> f;
                function<int(int,int)> f;
                switch(op) {
                    case '+': f = huahua::add; break;
                    case '-': f = huahua::minus; break;
                    case '*': f = huahua::multiply; break;
                }
                
                // Combine the solution
                for(int a : l) {
                    for(int b : r) {
                        ans.push_back(f(a,b));
                    }
                }
            }
        }
        
        // Single number, e.g. s = "3"
        if(ans.empty())
            ans.push_back(std::stoi(input));
        
        // memorize the answer for input
        m_[input].swap(ans);
        return m_[input];
    }
    
    unordered_map<string, vector<int>> m_;
};
