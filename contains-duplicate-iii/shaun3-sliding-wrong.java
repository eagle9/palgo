/*

k is the time window, within the window, value diff <= t
for each window O(N) windows, window size is k, check diff, k^2 time
if found any violation, return false
passing all tests, return true

improve? 
for the k values in the window
  track min and max, O(k), if max - min > t, false
improve more? 
  sliding window, remove left and add right, O(1) time to get updated sorted number in the window
  
  bingo
but my code not passing all tests
*/
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums.length == 0) return false;
        TreeSet<Integer> window = new TreeSet<>();
        /*
        for (int i = 0; i <=k && i < nums.length; i++) {
            window.add(nums[i]);
        }
        */
       
        for (int i = 0; i < nums.length; i++) {
            
            if (i <=k) { //0 --- k
                window.add(nums[i]);
                
            }else { //i = k+1
                window.remove(nums[i-k-1]); //remove left
                window.add(nums[i]);
            }
            boolean first = true;
            int prev = 0;
            for (int x: window) {
                if (first) {
                    prev = x;
                    first =true;
                    continue;
                }
                if (x - prev > k) {
                    prev = x;
                    continue;
                }
                else {
                    return true;
                }
                
            }
            
            //if there exist a pair of numbers in the window their diff <=t
            //can not found ---> any pair diff > k
            
            
            
        }
        
        //passing all tests
        return false;
    }
}
