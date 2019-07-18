//first sub not accepted, know the idea direction, but vague 
//shaun own idea, 
//runtime 16ms, faster than 95%, mem less than 60%
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i: nums) {
            res ^= i;  //tried & first, not a sharp thinking day
        }
        return res;
    }
};
