class Solution {
    //grandyang idea, very clean idea, shaun coded from the idea, beats 100%
    public boolean detectCapitalUse(String word) {
        int n = word.length();
        int countUpper = 0;
        for (int i =0; i < n; i++) {
            char c = word.charAt(i);
            if (c >= 'A' && c <= 'Z')
                countUpper++;
        }
        
        if (countUpper == 0 || countUpper == n) return true;
        if (countUpper == 1 && Character.isUpperCase(word.charAt(0))) return true;
        return false;
    }
}
