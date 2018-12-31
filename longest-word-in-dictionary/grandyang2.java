//grandyang greedy idea, shaun java code, beats 25%
class Solution {
    public String longestWord(String[] words) {
        String res = "";
        Set<String> set = new TreeSet<>();
        Arrays.sort(words);
        
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            String word1 = word.substring(0, word.length()-1);
            //either init case with single letter word
            //or minus 1 already in dict
            if (words[i].length() == 1 || set.contains(word1)) {
                res = (word.length() > res.length())? word: res;
                set.add(word);
            }
        }
        
        return res;
        
    }
}

/*
class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> s;
        sort(words.begin(), words.end());
        for (string word : words) {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
                res = (word.size() > res.size()) ? word : res;
                s.insert(word);
            }
        }
        return res;
    }
};
*/
/*
其实我们只要给数组排个序，就可以使用贪婪算法来做了，并不需要什么DFS或BFS这么复杂。首先建立一个空的哈希set，然后我们直接遍历排序后的字典，对于当前的单词，如果当前单词长度为1，或者该单词去掉最后一个字母后在集合中存在，这也不难理解，长度为1，说明是起始单词，不需要的多余的判断，否则的话就要判断其去掉最后一个字母后的单词是否在集合中存在，存在的话，才说明其中间单词都存在，因为此时是从短单词向长单词遍历，只要符合要求的才会加入集合，所以一旦其去掉尾字母的单词存在的话，那么其之前所有的中间情况都会在集合中存在。我们更新结果res时，要判断当前单词长度是否大于结果res的长度，因为排序过后，默认先更新的字母顺序小的单词，所有只有当当前单词长度大，才更新结果res，之后别忘了把当前单词加入集合中，
*/
