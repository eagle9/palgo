//understood
class Solution {
    public String minRemoveToMakeValid(String s) {
        int open=0; //unmatched open parenth
        StringBuilder ans= new StringBuilder();
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==')')
            {
                if(open>0) {
                    ans.append(s.charAt(i));
                    open--;
                }  
            }
            else if(s.charAt(i)=='(')
            {
                ans.append(s.charAt(i));
                open++;
            }
            else
            {
                ans.append(s.charAt(i));
            }
        }
        
        if(open==0) {
            return ans.toString();
        }
        //else if(open>0) {
            StringBuilder res = new StringBuilder();
            for(int i=ans.length()-1;i>=0;i--)
            {
                if(ans.charAt(i)=='(' && open>0) // no. of invalid openings
                {
                    open--;
                }
                else //right paren or open == 0
                {
                    res.append(ans.charAt(i));
                }
            }
            return res.reverse().toString();
        //}
        //return "";
    }
}

