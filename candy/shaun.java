//grandyang idea, shaun java code, finish the code very quickly, but got wrong answer, think more, figure out a fix and get accepted. 
//runtime is 2ms, faster than 100%
class Solution {
    public int candy(int[] ratings) {
        int [] candies = new int[ratings.length];
        //each child gets at least one candy
        Arrays.fill(candies, 1);
        //increase the candy count according to rule no. 2 
        
        //check neighbor rule for each children, from left to right
        //from child i to n-1, check if its ratings > left neighbor
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i-1] < ratings[i]) candies[i] = candies[i-1]+1;
        }
        
        //still check neighbor rule, from right to left
        for (int i = ratings.length-2; i >= 0; i--) {
            if (ratings[i+1] < ratings[i]) {
                if (candies[i] <= candies[i+1]) candies[i] = candies[i+1]+1;
                //else no need to update, already more candies
            }
        }
        
        int res = 0;
        for (int i: candies) res+=i;
        return res;
    }
}
