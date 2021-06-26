//shaun's sliding window idea with hashmap and two pointers,  first sub wrong answer, second sub accepted
//runtime 24ms, faster than 65%, mem less than 65%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char,int> mi; //hashmap from char to its index
        //the map will be the sliding window, new char is added when it is not yet in the window
        //if the new char is already in the window, remove chars from left to this char's index previously seen 
        
        int n = s.size(), left = 0, right = 0;
        int longest = 0;
        for (; right < n; ++right) {
            if (mi.count(s[right])) {
                int idx = mi[s[right]]; //find the cur char's index, remove char from left to idx
                for (int i = left; i <= idx; ++i) {
                    mi.erase(s[i]);
                }
                
                left = idx + 1; //move left to idx+1
                
            }
            mi[s[right]] = right;
            
            longest = max(longest, right-left+1);
        }
        return longest;
    }
};
