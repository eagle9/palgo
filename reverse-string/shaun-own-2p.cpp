//runtime 44ms, faster than 94%, mem less than 58%
//shaun own idea with 2 pointers left and right moving towards each other
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        int len = s.size(); 
        if (len == 1) return;
        
        int left = 0, right = len -1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        
    }
};

