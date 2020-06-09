class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        int []a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nums[i];
        }    
        for (int i = 0; i < n; ++i) {
            //if nums[i] in [0,n]: nums[i] to be stored in at index nums[i]-1
            //key point here is to do this with a while loop
            while (a[i] > 0 && a[i] <= n &&  a[i] != a[a[i] - 1]) {
                int j = a[i]-1;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                //nums[i] changed here
                //this loop keep to put nums[i] into its correct bucket
                //exit when its out of [0,n] range or correct bucket
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != i + 1) return i + 1;
        }
        //found 1 to n present
        return n + 1;

    }
    
}
