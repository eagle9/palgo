//shaun own idea, accepted after 1 bug fix
// fix 1 --- ai != bi, break
//runtime 4ms, faster than 98.62%, mem less than 52%
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            prefix = find_prefix(strs[i], prefix);
        }
        return prefix;
    }
private:
    //longest prefix of a and b
    string find_prefix(string a, string b) {
        int i = 0, len = min(a.size(),b.size());
        //if (len == 0) return ""; //after comment, okay too
                             
        while (i < len ) {
            if (a[i] == b[i]) i++;
            else break; ///bug fix 1
        }
        //i == number of equal chars
        return a.substr(0,i);
    }
};

/*
xiaoquang, brute force is better
Runtime: 4 ms, faster than 98.62% of C++ online submissions for Longest Common Prefix.
Memory Usage: 8.9 MB, less than 61.60% of C++ online submissions for Longest Common Prefix.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end());
        return find_prefix(strs[0], strs[strs.size()-1]);
    }
private:
    //longest prefix of a and b
    string find_prefix(string a, string b) {
        int i = 0, len = min(a.size(),b.size());
        //if (len == 0) return ""; //after comment, okay too
                             
        while (i < len ) {
            if (a[i] == b[i]) i++;
            else break; ///bug fix 1
        }
        //i == number of equal chars
        return a.substr(0,i);
    }
};
