//jz java, recursive, use dfs recursive template
//Your submission beats 74.20% Submissions!

public class Solution {
    public List<String> stringPermutation2(String str) {
        List<String> result = new ArrayList<>();
        if (str == null) {
            return result;
        } 
        if (str.length() == 0) {
            result.add("");
            return result;
        }
        
        //sort string
        str = sortString(str);
        
        dfs(str, "", result, new boolean[str.length()]);
        return result;
    }
    
    private void dfs(String str, String subset, List<String> result, boolean[] visited) {
        if (subset.length() == str.length()) {
            //exit of recursion
            result.add(subset);
            return;
        }
        
        for (int i = 0; i < str.length(); i++) {
            if (visited[i]) {
                continue;
            }
            
            if (i > 0 && str.charAt(i) == str.charAt(i - 1) && !visited[i - 1]) {
                //remove duplicates
                continue;
            }
            
            visited[i] = true;
            dfs(str, subset + str.charAt(i), result, visited);
            visited[i] = false;
        }
    }
    
    private String sortString(String str) {
        char[] charArray = str.toCharArray();
        Arrays.sort(charArray);
        str = new String(charArray);
        return str;
    }
}
