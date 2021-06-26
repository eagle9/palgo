//grandyang idea2, shaun java code, beats 76%
/*
idea1 方法中用到了sort排序，对于数组中单词的数量不是很多，但是长度特别长的情况很适用，但是如果对于单词数量特别多，但是每个都不长的话，排序的O(nlgn)时间复杂度可能就不是最好的方法了，也可以不用排序来做。我们遍历字典中的单词，然后还是跟上面的方法一样来验证当前单词是否能由字符串s通过删除字符来得到，如果能得到，而且单词长度大于等于结果res的长度，我们再看是否需要更新结果res，有两种情况是必须要更新结果res的，一个是当前单词长度大于结果res的长度，另一种是当前单词长度和res相同，但是字母顺序小于结果res，这两种情况下更新结果res即可
*/
class Solution {
    public String findLongestWord(String s, List<String> dict) {
        //If there is no possible result, return the empty string.
        String res = "";
        //for each word in the dictionary, can the word be derived from deleting some chars from s???
        for (String word : dict) {
            int i = 0;
            //how many chars in word show up s???
            for (char c : s.toCharArray()) {
                if (i < word.length() && c == word.charAt(i)) ++i;
            }
            
            //all chars in word found in s in order
            if (i == word.length() && word.length() >= res.length()) {
                //If there are more than one possible results, return the longest word with the smallest lexicographical order
                if (word.length() > res.length() || word.compareTo(res) < 0) {
                    res = word;
                }
            }
        }
        return res;
    }
}
/*
grandyang idea1, shaun java code, beats 74%
只能老老实实的按顺序遍历每一个字符。我们可以给字典排序，通过重写comparator来实现按长度由大到小来排，如果长度相等的就按字母顺序来排。然后我们开始遍历每一个单词，用一个变量i来记录单词中的某个字母的位置，我们遍历给定字符串，如果遍历到单词中的某个字母来，i自增1，如果没有，就继续往下遍历。这样如果最后i和单词长度相等，说明单词中的所有字母都按顺序出现在了字符串s中，由于字典中的单词已经按要求排过序了，所以第一个通过验证的单词一定是正确答案，我们直接返回当前单词即可
*/
class Solution1 {
    public String findLongestWord(String s, List<String> dict) {
        Collections.sort(dict, new Comparator<String>(){
            public int compare(String a, String b) {
                //lexicography order if same length
                if (a.length() == b.length()) return a.compareTo(b);
                //longer String first
                return b.length() - a.length();
            } 
        });
        
        //two pointers: i for word in dict, j for target s
        for (String word : dict) {
            int i = 0;
            char [] chars = s.toCharArray();
            int n = word.length();
            for (int j = 0; j < chars.length && i < n; j++) {
                if ( chars[j] == word.charAt(i)) i++;
            }
            
            if (i == n) return word;
        }
        return "";
    }
}
