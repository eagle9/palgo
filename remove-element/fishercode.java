class Solution {
    //beats 99%, fishercode 
    public int removeElement(int[] nums, int val) {
      int index = 0; //for non val elements
      for (int j = 0; j < nums.length; j++) {
        if (nums[j] != val) { //only care about values != val
          nums[index++] = nums[j]; //put nums[j] to deserved place
        }
      }
      return index;  //i is the number of non val elements
    
    }
}
