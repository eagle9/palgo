/*
Runtime: 4 ms, faster than 86.48% of Java online submissions for Wiggle Sort II.
Memory Usage: 31.3 MB, less than 20.21% of Java online submissions for Wiggle Sort II.
grandyang idea1 sorting
very close to my original idea
*/
class Solution1 {
    //Time O(nlogn), space O(n)
    public void wiggleSort(int[] nums) {
        int n = nums.length;
        int [] tmp = new int[n];
        for (int i = 0; i < n; i++) tmp[i] = nums[i];
        Arrays.sort(tmp);
        int k = (1+n)/2, j = n;
        for (int i = 0; i < n; i++) {
            //nums[i] = (i % 2 == 0)? tmp[k--]: tmp[j--];
            if ( i % 2 == 0) {
                nums[i] = tmp[--k];
            }else {
                nums[i] = tmp[--j];
            }
        }
    }
}

