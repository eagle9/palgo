class Solution {
    //huahua idea, shaun java code, beats 19%
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        int [] ca = new int[26];
        int [] cb = new int[26];
    
        int diff = 0;
        for (int i = 0; i < A.length(); ++i) {
            if (A.charAt(i) != B.charAt(i)) {
                diff++;
                if (diff > 2) return false;
            } 
            ca[A.charAt(i)-'a']++;
            cb[B.charAt(i)-'a']++;
        }
        //if (diff == 2) return true;// must ensure letter count equal in both string
        for (int i = 0; i < 26; ++i) {
            //diff == 0, must have 1 letter that shows up 2+ times
            if (diff == 0 && ca[i] >= 2) return true;
            //any
            if (ca[i] != cb[i]) return false;
        }
        
        //now letter count equal in both string tested
        return diff == 2;
    }
    
    
}
