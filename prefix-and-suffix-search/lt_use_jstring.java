/*Runtime: 1790 ms, faster than 8.24% of Java online submissions for Prefix and Suffix Search.
Memory Usage: 62.6 MB, less than 99.32% of Java online submissions for Prefix and Suffix Search.

https://leetcode.com/problems/prefix-and-suffix-search/discuss/110044/three-ways-to-solve-this-problem-in-java
*/
class WordFilter {
    String[] input;
    public WordFilter(String[] words) {
        input = words;
    }
    public int f(String prefix, String suffix) {
        for(int i = input.length-1; i >= 0; i--){
            if(input[i].startsWith(prefix) && input[i].endsWith(suffix)) return i;
        }
        return -1;
    }
}


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
