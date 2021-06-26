public class Solution {
    /**
     * @param list: The coins
     * @param k: The k
     * @return: The answer
     */
    public int takeCoins(int[] list, int k) {
        // Write your code here
        
        //check if k > list.length
        int left = 0, right = list.length-1;
        int value = 0;
        for (int i = 1; i <= k; i++) {
            if (list[left] > list[right]) {
                value += list[left];
                left++;
            }else { //left <= right
                value += list[right];
                right--;
            }
        }
        return value;
    }
	public static void main(String[] args) {
			Solution s = new Solution();
			int [] list = {5,4,3,2,1,6};
			int res = s.takeCoins(list,3);
			System.out.println(res);
	}
    
}
