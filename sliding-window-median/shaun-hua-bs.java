// Author: Huahua
// Running time: 47 ms (<98.96%)
// keep the window of k elements sorted, remove and insert
//  since the window is sorted, so easier to get the window median each time
class Solution {
  public double[] medianSlidingWindow(int[] nums, int k) {
    if (k == 0) return new double[0];
      /*
      nums: 1 2 3 4 5, k =3 
      123. 234 345, 3 windows => ans size =3
      5 - 3 + 1 = 3
      */
    double[] ans = new double[nums.length - k + 1];
    int[] window = new int[k];
    //from 0 to k-1
    for (int i = 0; i < k; ++i) 
      window[i] = nums[i];
    Arrays.sort(window);
    
    //from k to end
    for (int i = k; i <= nums.length; ++i) {
      //ans[i - k] = ((double)window[k / 2] + (double)window[(k - 1)/2]) / 2;
      ans[i-k] = median(window, k);
      if (i == nums.length) break;
      remove(window, nums[i - k]); //remove left 
      insert(window, nums[i]); //add right
    }
    return ans;
  }
    //shaun add this function to easy it out
  double median(int [] a, int k) {
      //1 2 3 4 5, k = 5
       // 3 index = 2 = 5/2
      if (k % 2 == 1) {
          return (double)a[k/2];
      }
      else {
        //1 2 3 4, k = 4
        // 2 3 index 1 2, 
        return ((double)a[k/2] + (double)a[k/2-1])*0.5;
      }
  }
  // Insert val into window, window[k - 1] is empty before inseration
  private void insert(int[] window, int val) {
      //index of the search key, if it is contained in the array; otherwise, (-(insertion point) – 1)
    int i = Arrays.binarySearch(window, val);
    if (i < 0) i = - i - 1;    
    int j = window.length - 1;
    while (j > i) window[j] = window[--j];
    window[j] = val;
  }
  
  // Remove val from window and shrink it.
  private void remove(int[] window, int val) {
    int i = Arrays.binarySearch(window, val);
    while (i < window.length - 1) window[i] = window[++i];
  }
  
}
