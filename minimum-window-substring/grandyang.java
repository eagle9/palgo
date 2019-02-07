//grandyang idea sliding window
//runtime 6ms, faster than 84%
//Jan 31 2019

class Solution {
    public String minWindow(String s, String t) {
        
        int minLen = Integer.MAX_VALUE;
        String res = "";
        
        //letter cnt of stringt
        //how many mataches we need to find for each c in t
        int [] letterCnt = new int[128];
        char [] ss = s.toCharArray();
        char [] tt = t.toCharArray();
        
        for (char c: tt) letterCnt[c]++;
        
        //left of window, cnt of matched letters
        int left = 0, cnt = 0;
        for (int i = 0; i < ss.length; i++) {
            //add char i to sliding window
            //T needs one fewer letter, still needs >=0, then letter i contributes to cnt
            if (--letterCnt[ss[i]] >= 0) cnt++;
            
            //if or while???, use the example to figure this out
            while (cnt == tt.length) {
                if (i-left+1 < minLen) {
                    minLen = i-left+1;
                    //substring from left to i, so end index is i+1
                    res = s.substring(left,i+1);
                }
                //remove left from sliding window
                // T need one more letter 
                //update cnt if the letter count needed by T >0
                if (++letterCnt[ss[left]] > 0) cnt--;
                left++;
            }
        }
        return res;
    }
}

