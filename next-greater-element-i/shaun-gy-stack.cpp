//shaun's original idea, naive,  accepted first sub
//
//runtime 20ms, faster than 16%, mem less than 17%
/*
    unique numbers in both array, 1 is a subset of 2
    output next greater of 1
    focus on nums2, hash: number to its next greater, for each i, then from j= i+1 to end, if nums2[j] > nums2[i],  nums2[i] --> nums2[j]
    time O(n^2)
    why stack? --- O(n)
    // 1 3 4 2 ---- 1 3 4, monotonic stack
*/



//shaun upon hint of using stack to get next greater element
//runtime 8ms, faster than 99%, mem less than 12%
/*
1 3 4 2
1 2 4 5 6 3 2 7
cutting: push all numbers into stack, once a new number > stack top,  pop out, and small -> new number
doing so, inside the stack, each number is followed by smaller numbers
each number is pushed and popped once, so O(n) time and O(n) space

runtime 8ms, faster than 98%, mem less than 66%
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
       
        stack<int> st;
        unordered_map<int, int> m;
        for (int num : nums) {
            while (!st.empty() && st.top() < num) {
                m[st.top()] = num; st.pop();
            }
            st.push(num);
        }
        int n = findNums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            if (m.count(findNums[i])) res[i] = m[findNums[i]];
        }        
        return res;
    }
};
