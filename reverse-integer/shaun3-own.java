/*
get digit by digit

shaun own idea and code,
accepted after 3 bug fixes
Runtime: 12 ms, faster than 5.94% of Java online submissions for Reverse Integer.
Memory Usage: 37.7 MB, less than 5.55% of Java online submissions for Reverse Integer.
*/
class Solution {
    public int reverse(int x) {
        if (x == 0) return x;
        
        int sign = x >0? 1: -1;
        int y = x * sign;
        List<Integer> list = new ArrayList<>();
        while ( y > 0 ) { //bug ---> y/10>0
            int digit = y % 10;
            
            list.add(digit);
            y = y/10;
        }
        
        //reconstruct the number from digits
        int res = 0;
        for (int i=0; i < list.size(); i++) {
            int d = list.get(i);
            System.out.println(d);
            if (res > Integer.MAX_VALUE/10) return 0; //bug >=
            res = res*10 + d;
            //bug res+= res*10 + d
            
        }
        return res*sign;
    }
}
