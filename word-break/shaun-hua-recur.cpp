// hua memoized recursion, shaun read and understands, modified
//naturally starter solution 

//cutting, very natural with recur
//think about it, word = left + right, if left in dict, recur break right
//   either break right or left works
//  use memo to speed up to avoid repeated computation
//break details: left = substr(0, j), j = 1 to n-1, j = n is not breaking the word
//   right start index = ?   lef end index = 0 + j -1 = j-1, so right start j
// right = s.substr(j)  to end, no len para
//runtime 16ms, faster than 61%, mem less than 22%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Create a hashset of words for fast query.
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        // Query the answer of the original string.
        return wordBreak2(s, dict);
    }
    
    bool wordBreak(const string& s, const unordered_set<string>& dict) {
        // In memory, directly return.
        if(mem_.count(s)) return mem_[s];
        // Whole string is a word, memorize and return.
        if(dict.count(s)) return mem_[s]=true;
        // Try every break point.
        // left right   right from all to 1 char
        for(int j=0;j<s.length();j++) { //j= 0, j=1 both work, but j=0 
            const string left = s.substr(0,j); //len=b-a+1, b = a+len-1
            const string right = s.substr(j);
            // Find the solution for s.
            if(dict.count(right) && wordBreak(left, dict))
                return mem_[s]=true;
        }
        // No solution for s, memorize and return.
        return mem_[s]=false;
    }
    
    //
    bool wordBreak2(const string& s, const unordered_set<string>& dict) {
        // In memory, directly return.
        if(mem_.count(s)) return mem_[s];
        // Whole string is a word, memorize and return.
        if(dict.count(s)) return mem_[s]=true;
        // Try every break point.
        // left right   right from all to 1 char
        for(int j=0;j<s.length();j++) { //j= 0, j=1 both work, but j=0 
            const string left = s.substr(0,j); //len=b-a+1, b = a+len-1
            const string right = s.substr(j);
            // Find the solution for s.
            if(dict.count(left) && wordBreak2(right, dict))
                return mem_[s]=true;
        }
        // No solution for s, memorize and return.
        return mem_[s]=false;
    }
private:
    unordered_map<string, bool> mem_;
};

