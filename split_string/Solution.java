//jz java Your submission beats 76.60% Submissions!
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
    
    private void dfs(String s,  List<String> local, List<List<String>> res){
        if(s.equals("")){
            res.add(new ArrayList<String>(local));
            return;
        }
                        
        for(int i = 1; i <= 2; i++){
            if(i <= s.length()){
                local.add(s.substring(0, i));
                dfs(s.substring(i, s.length()), local, res);
                local.remove(local.size() - 1);
            }
        }
    }
}

