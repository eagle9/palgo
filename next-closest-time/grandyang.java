public class Solution {
    
    //grandyang idea, shaun modified for natural thinking in java, beats 94%
    //key point: candidate string uses 4 char StringBuilder
    //key point: int to char conversion in java
    public String nextClosestTime(String time) {
        StringBuilder res = new StringBuilder("0000");
        // first digit 1 or 2, 10 hours for 1, > 10 hours for 2, 10 hours = 600 min
        // second digit 0 - 9, how many hours left after 10 hours
        //3rd digit, how many 10s of minutes
        //4th digit, single minute
        int [] mod = {600, 60, 10, 1};   
        int iComma = time.indexOf(":");
        int hour = Integer.parseInt(time.substring(0,iComma));
        int minu = Integer.parseInt(time.substring(iComma+1));
        //current time in number of minutes from 00:00
        int cur = hour * 60 + minu;
        //for each minute, generate 4 char string
        //make sure each char is in input time string
        for (int i = 1; i <= 1440; ++i) {
            //add minutes to current
            int next = (cur + i) % 1440;
            //get digit string from next, check if digit generated is in input time
            //use only digits that are in input time
            int countMatch = 0;
            for (int d = 0; d < 4; ++d) {
                char digit = (char) (next / mod[d] + '0');
                //char digit = Character.valueOf(next / mod[d]); //error, lossy conversion from int to char
                if (time.indexOf(digit) < 0) break;
                else countMatch++;
                
                res.setCharAt(d,digit); 
                next %= mod[d];
            }
            //d >= 4 all 4 proposed digits found in the input time string
            if (countMatch == 4) break;
        }
        //must has result
        return res.substring(0, 2) + ":" + res.substring(2);
    }
};
