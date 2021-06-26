//jz java Your submission beats 80.00% Submissions!
public class Solution {
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    public List<List<String>> splitString(String s) {
        // write your code here
        List<List<String>> res = new ArrayList<>();
        List<String> local = new ArrayList<>();
        
        dfs(s,  local, res);
        
        return res;
    }
    

    
    //a general dfs loop 
    // s is the string, each time choose the first char, then choose the second char, then pass on the remaining characters for recursion
    
    /*
    @param: s is the string to be split
            c is the candidate
            res is the results
    */
    private void dfs(String s,  List<String> c, List<List<String>> res){
        //recursion exit: s shortened to empty, candidate is ready
        if(s.equals("")){
            res.add(new ArrayList<String>(c));
            return;
        }
                        
        //why recusion like this,  split after char and split after first 2 chars, because the problem asks so
        for(int i = 1; i <= 2; i++){
            if(i <= s.length()){
                String p1 = s.substring(0, i), p2 = s.substring(i, s.length());
                c.add(p1); 
                dfs(p2, c, res);
                c.remove(c.size() - 1); //remove the last item from c, back tracking,restore 
            }
        }
    }
}
