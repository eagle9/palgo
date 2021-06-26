
class Solution {

    //grandyang brute force idea, shaun java code, beats 9%
    class Solution1 {

        public int [] nextGreaterElements(int [] nums) {
            int n = nums.length;
            int [] res = new int[n];
            for (int i = 0; i < n; i++)  res[i] = -1;

            for (int i = 0; i < n; i++) {
                //for each nums[i], from i+1 to i + n % n, find greater
                for (int j = i + 1; j < i + n; ++j) {

                    if (nums[j % n] > nums[i]) {
                        res[i] = nums[j % n];
                        break;
                    }
                }
                //if not set, res is the default -1
            }
            return res;
        }
    };
    /*
    用栈来进行优化上面的算法，我们遍历两倍的数组，然后还是坐标i对n取余，取出数字，如果此时栈不为空，且栈顶元素小于当前数字，说明当前数字就是栈顶元素的右边第一个较大数，那么建立二者的映射，并且去除当前栈顶元素，最后如果i小于n，则把i压入栈。因为res的长度必须是n，超过n的部分我们只是为了给之前栈中的数字找较大值，所以不能压入栈
    grandyang idea with stack, shaun translated to java, beats 73%
    */
    public int [] nextGreaterElements(int [] nums) {
        
        int n = nums.length;
        int [] res = new int[n];
        for (int i = 0; i < n; i++) res[i] = -1;
        
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.peek()] < num) {
                res[st.peek()] = num; 
                st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
    
}
