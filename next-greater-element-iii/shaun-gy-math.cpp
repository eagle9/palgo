/*
比如12443322，这个数字的重排序结果应该为13222344
grand yang idea to find next permutation, very similar to the idea that used in "Next Permutation"
cutting: from right(lowest digit) to find the first digit that can get bigger (how? the first number that gone down, so it has potential to get bigger, right?)
say this number(went down number) at index i-1
begin   i-1 i        end
to make this bigger, before i-1, no change
after i-1, from end, find a number that > nums[i-1], swap then
then make i .. end to be the smallest, or sort it

runtime 0ms, faster than 100%, mem less than 91%
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), i = len - 1;
        //from right, find the first number(index i-1) that gone down
        for (; i-1 >= 0; --i) {
            if (str[i-1] < str[i]) break;
        }
        //if i ==0, that means all number going up, at max, no next greater, return -1
        if (i == 0) return -1;
        
        //from right, find greater than i-1, and swap them, to get bigger
        //      [i            len-1] <--in this range, find greater
        // i-1
        for (int j = len - 1; j >= i; --j) {
            if (str[j] > str[i - 1]) {
                swap(str[j], str[i - 1]);
                break;
            }
        }
        //i-1 got bigger, i to end to be minimized
        sort(str.begin() + i, str.end());
        
        //long long res = stoll(str);
        long res = stol(str);
        return res > INT_MAX ? -1 : res;
    }
};
