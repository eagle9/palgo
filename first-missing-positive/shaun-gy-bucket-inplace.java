//the challenge is linear time and constant space
//grandyang idea, shaun understood, put number to index = value -1
//all non-missing positive number should be at value -1 index
//missing one will be detected O(n) scan and check
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
            //but this won't be n^2 time, since out of place number <= n
            while (a[i] > 0 && a[i] <= n &&  a[i] != a[a[i] - 1]) {
                int j = a[i]-1; //use value for index
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                //nums[i] changed here
                //this loop keep to put nums[i] into its correct bucket
                //exit when its out of [0,n] range or correct bucket
            }
        }
        for (int i = 0; i < n; ++i) {
            //now all number should be put to index = value-1 
            if (a[i]!= i + 1) return i + 1;
        }
        //found 1 to n present
        return n + 1;

    }
}
