class Solution {
    //shaun's own idea, accepted after updating with test cases
	//O(n) time, O(1) space
    //beats 96%
	//simiar to grandyang idea
	//
    //52325
    //52325 /10000 = 5,  52325 %10 = 5
    // x % 10000 = 2325,  2325/10 = 232
    //232 /100 = 2,  232%10 = 2
    // x % 100 = 32, 32/10 = 3
    // 3 < 10
    
    //digit pair: 5225 /1000 = 5,  5225 %10 = 5
    // next: x % 1000 = 225,  225/10 = 22
    //digit pair: 22 /10 = 2,  2%10 = 2
    // next: x % 10 = 2, 2/10 = 0
    //
	//1000021
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        //find the biggest div
        int div = 10;
        while (x / div >= 10) {
            div *= 10;
            //System.out.println(x + " "  + div);
        }
        //now x/div < 10
        //while (x >= 10 && div >= 10) { // wrong answer
        while (div >= 10) {
            int left = x/div, right = x%10;
            //System.out.println(left + " " + right + " " + div);
            if (left != right) return false;
            x %=div; 
            x /= 10;
            div /=100;
            //System.out.println("x=" + x + ",div=" + div);
                
            
        }
        return true;
    }
}
