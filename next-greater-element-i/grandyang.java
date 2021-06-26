class Solution {
    //brute force solution, grandyang idea, shaun code in java, beats 5%
    class Solution1 {
        public int[] nextGreaterElement(int[] nums1, int[] nums2) {
            int [] res = new int[nums1.length];
            for (int i = 0; i < nums1.length; i++) {
                int j = 0, k = 0;

                //for each nums1[i], find nums2[j] ==
                for (; j < nums2.length; j++) {
                    if (nums2[j] == nums1[i]) break;
                }
                //find nums2[k] > nums2[j]
                for (k = j+1; k < nums2.length; k++) {
                    if (nums2[k] > nums2[j]) {
                        //found next greater, done
                        res[i] = nums2[k];
                        break;
                    }
                }
                //which loop exit condition? 
                if (k == nums2.length) res[i] = -1;
            }
            return res;

        }
    }
    
    class Solution2 {
        /*
        对上面的方法稍做优化，我们用哈希表先来建立每个数字和其坐标位置之间的映射，那么我们在遍历子集合中的数字时，就能直接定位到该数字在原数组中的位置，然后再往右边遍历寻找较大数即可
        grandyang idea3 with stack, shaun java code, beats 62%
        */
        public int[] nextGreaterElement(int[] nums1, int[] nums2) {
                int [] res = new int[nums1.length];

                Map<Integer,Integer> map = new HashMap<>();
                //numbers in nums2 are unique
                for (int i = 0; i < nums2.length; i++) {
                    map.put(nums2[i], i);
                }

                for (int i = 0; i < nums1.length; i++) {
                    //find nums2[j] == nums1[i]
                    int j = map.get(nums1[i]);
                    //find nums2[k] > nums2[j]
                    int k = j + 1;
                    for (; k < nums2.length; k++) {
                        if (nums2[k] > nums2[j]) {
                            //found next greater, done
                            res[i] = nums2[k];
                            break;
                        }
                    }
                    //which loop exit condition? 
                    if (k == nums2.length) res[i] = -1;
                }
                return res;
        }
    }
    
    /*
    使用了哈希表和栈，但是这里的哈希表和上面的不一样，这里是建立每个数字和其右边第一个较大数之间的映射，没有的话就是-1。我们遍历原数组中的所有数字，如果此时栈不为空，且栈顶元素小于当前数字，说明当前数字就是栈顶元素的右边第一个较大数，那么建立二者的映射，并且去除当前栈顶元素，最后将当前遍历到的数字压入栈。当所有数字都建立了映射，那么最后我们可以直接通过哈希表快速的找到子集合中数字的右边较大值
    grandyang idea3, shaun java code, wrong answer
    
    */
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int [] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            res[i] = -1;
        }
        Stack<Integer> st = new Stack<>();
        Map<Integer,Integer> m = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            int num = nums2[i];
            while (!st.empty() && st.peek() < num) {
                m.put(st.peek(),num);
                
                st.pop();
            }
            //st is empty or st.peek() >= num
            st.push(num);
        }
        
        for (int i =0; i < nums1.length; i++) {
            int num = nums1[i];
            if (m.containsKey(num))
                res[i] = m.get(num);
        }
        return res;
    }
}
