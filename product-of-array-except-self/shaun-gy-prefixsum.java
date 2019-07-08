/*
给定我们一个数组，让我们返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，并且限定了时间复杂度O(n)，并且不让我们用除法。如果让用除法的话，那这道题就应该属于Easy，因为可以先遍历一遍数组求出所有数字之积，然后除以对应位置的上的数字。但是这道题禁止我们使用除法，那么我们只能另辟蹊径。我们想，对于某一个数字，如果我们知道其前面所有数字的乘积，同时也知道后面所有的数乘积，那么二者相乘就是我们要的结果，所以我们只要分别创建出这两个数组即可，分别从数组的两个方向遍历就可以分别创建出乘积累积数组。

grandyang idea1,shaun absorbed, cutting angle prefix sum --> prefix product for array
2ms, faster than 97%
*/
class Solution1 {
    public int[] productExceptSelf(int[] a) {
        int n = a.length;
        int [] fwd = new int[n], bwd = new int[n], res = new int[n];
        //a0 a1 a2 .. an-1
        //fwd[i] == a0 * a1 *... ai-1
        fwd[0] = 1;
        for (int i = 1; i <= n - 1; ++i) {
            fwd[i] = fwd[i-1] * a[i-1];
        }
        //an-1 an-2 ... a2 a1
        //bwd[i] = an-1 ... ai+1
        bwd[n-1] = 1;
        for (int i = n - 1; i >= 1; --i) {
            bwd[i - 1] = bwd[i] * a[i];
        }
        for (int i = 0; i < n; ++i) {
			//      n0..n[i-1]   n[i+1] ... n[n-1]
            res[i] = fwd[i] * bwd[i];
        }
        return res;
    }
}
/*
grandyang idea2, save a little more space, 2ms, faster than 97%
对上面的方法进行空间上的优化，由于最终的结果都是要乘到结果res中，所以我们可以不用单独的数组来保存乘积，而是直接累积到res中，我们先从前面遍历一遍，将乘积的累积存入res中，然后从后面开始遍历，用到一个临时变量right，初始化为1，然后每次不断累积，最终得到正确结果
*/
public class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length, right = 1;
        int[] res = new int[n];
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
}
