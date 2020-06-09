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
  
  
  check with lt java solution, 
  finally accepted, 
  Runtime: 17 ms, faster than 46.47% of Java online submissions for Contains Duplicate III.
Memory Usage: 39.3 MB, less than 6.82% of Java online submissions for Contains Duplicate III.
*/
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        
        TreeSet<Integer> window = new TreeSet<>();
        /*
        for (int i = 0; i <=k && i < nums.length; i++) {
            window.add(nums[i]);
        }
        */
        //window.add(nums[0]);
        for (int i = 0; i < nums.length; i++) {
            //with nums[i], find the first >= it, and first > it
            //check diff
            Integer right = window.ceiling(nums[i]);  //ceiling of given element >=, first
            if (right != null) {
                //long diff = Math.abs((long)right.intValue() - (long)nums[i]);
                //if (diff <= t) return true;
                if (nums[i] + t >= right) return true;
            }
            
            Integer left = window.floor(nums[i]) ; //< , max
            if (left != null ) {
                //long diff = Math.abs((long)nums[i] - (long)left.intValue());
                //if (diff <= t) return true;
                if ( left + t >= nums[i]) return true;
            }
            
            
            window.add(nums[i]);
            //nums element could repeat, use .size() problem?
            //will the window has i and j that differ more than k? 
            if (window.size() > k){
                window.remove(nums[i-k]);
            }
                /*
            if (i <=k) { //0 --- k
                window.add(nums[i]);
                
            }else { //i = k+1
                window.remove(nums[i-k-1]); //remove left
                window.add(nums[i]);
            }
            */
            
            
            //if there exist a pair of numbers in the window their diff <=t
            //can not found ---> any pair diff > k
            
            
            
        }
        
        //could not find pairs, return false
        return false;
    }
}
