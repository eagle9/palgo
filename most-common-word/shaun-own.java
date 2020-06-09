/*
Runtime: 8 ms, faster than 75.84% of Java online submissions for Most Common Word.
Memory Usage: 40.9 MB, less than 5.05% of Java online submissions for Most Common Word.

shaun own idea, accepted with 1 bug fix

*/
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        HashSet<String> ban = new HashSet<>();
        ban.addAll(Arrays.asList(banned));
        
        Map<String, Integer> strCnt = new HashMap<>();
        int mx = 0;
        StringBuilder sb = new StringBuilder();
        List<String> tokens = new ArrayList<>();
        for (char c: paragraph.toCharArray()) {
            if (Character.isAlphabetic(c)) {
                sb.append(Character.toLowerCase(c));
            }else {
                if (sb.length() >0) {
                    tokens.add(sb.toString());
                    sb = new StringBuilder();
                }
            }
        }
        //bug fix
        if (sb.length() >0) {
                    tokens.add(sb.toString());
                    sb = new StringBuilder();
                }
        
        
        String res = null;
        for (String token: tokens) {
            //only consider token not in banned set
            if (!ban.contains(token)) {
                int count = strCnt.getOrDefault(token,0);
                count++;
                strCnt.put(token, count);
                
                if (count > mx) {
            
                    
                    mx = count;
                    res = token;
                }
            }
        }
        return res;
    }
}
