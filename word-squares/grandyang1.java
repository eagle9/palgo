/*grandyang map of prefix idea, runtime 70ms, faster than 85%
not fully understand
Valid Word Square的延伸，由于要求出所有满足要求的单词平方，所以难度大大的增加了，不要幻想着可以利用之前那题的解法来暴力破解，OJ不会答应的。那么根据以往的经验，对于这种要打印出所有情况的题的解法大多都是用递归来解，那么这题的关键是根据前缀来找单词，我们如果能利用合适的数据结构来建立前缀跟单词之间的映射，使得我们能快速的通过前缀来判断某个单词是否存在，这是解题的关键。对于建立这种映射，这里主要有两种方法，一种是利用哈希表来建立前缀和所有包含此前缀单词的集合之前的映射，第二种方法是建立前缀树Trie，顾名思义，前缀树专门就是为这种问题设计的。那么我们首先来看第一种方法，用哈希表来建立映射的方法，我们就是取出每个单词的所有前缀，然后将该单词加入该前缀对应的集合中去，然后我们建立一个空的nxn的char矩阵，其中n为单词的长度，我们的目标就是来把这个矩阵填满，我们从0开始遍历，我们先取出长度为0的前缀，即空字符串，由于我们在建立映射的时候，空字符串也和每个单词的集合建立了映射，然后我们遍历这个集合，用遍历到的单词的i位置字符，填充矩阵mat[i][i]，然后j从i+1出开始遍历，对应填充矩阵mat[i][j]和mat[j][i]，然后我们根据第j行填充得到的前缀，到哈希表中查看有没单词，如果没有，就break掉，如果有，则继续填充下一个位置。最后如果j==n了，说明第0行和第0列都被填好了，我们再调用递归函数，开始填充第一行和第一列，依次类推，直至填充完成

*/
class Solution {
    public List<List<String>> wordSquares(String[] words) {
        List<List<String>> res = new ArrayList<>();
        Map<String,Set<String>> map = new HashMap<>();
        int n = words[0].length();
        for (String word: words) {
            for (int i = 0; i < n; i++) {
                String prefix = word.substring(0,i); //0 to i-1, len = i chars
                Set<String> set = map.getOrDefault(prefix, new HashSet<>());
                set.add(word);   //all kind of prefix --> word
                map.put(prefix, set);
            }
        }
        char [] [] mat = new char[n][n];
        helper(0,n,mat,map,res);
        return res;
    }
    private void helper(int i, int n, char [][] mat, Map<String,Set<String>> map, List<List<String>> res) {
        if (i == n) {
            List<String> cand = new ArrayList<>();
            for (int j = 0; j < n; j++) cand.add(String.valueOf(mat[j]));
            
            res.add(cand);
            //key to return here
            return;
        }
        //String key = String.valueOf(mat[i]).substring(0,i);
        String key = String.valueOf(Arrays.copyOfRange(mat[i],0,i)); //chars from 0 to i
        Set<String> set = map.getOrDefault(key, new HashSet<>());
        for (String prefix: set) {
            mat[i][i] = prefix.charAt(i);
            int j = i + 1;
            for (; j < n; ++j) {
                mat[i][j] = prefix.charAt(j);
                mat[j][i] = prefix.charAt(j);
                String temp = String.valueOf(Arrays.copyOfRange(mat[j],0,i+1));
                if (!map.containsKey(temp)) break;
                //if (!m.count(string(mat[j].begin(), mat[j].begin() + i + 1))) break;
            }
            if (j == n) helper(i + 1, n, mat, map, res);
        }
    }
}

/*
//grandyang idea1 in c++, runtime 60ms, faster than 80%
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        unordered_map<string, set<string>> m;
        int n = words[0].size();
        for (string word : words) {
            for (int i = 0; i < n; ++i) {
                string key = word.substr(0, i);
                m[key].insert(word);
            }
        }
        vector<vector<char>> mat(n, vector<char>(n));
        helper(0, n, mat, m, res);
        return res;
    }
      void helper(int i, int n, vector<vector<char>>& mat, unordered_map<string, set<string>>& m, vector<vector<string>>& res) {
            if (i == n) {
                vector<string> out;
                for (int j = 0; j < n; ++j) out.push_back(string(mat[j].begin(), mat[j].end()));
                res.push_back(out);
                return;
            }
            string key = string(mat[i].begin(), mat[i].begin() + i);
        for (string str : m[key]) { 
            mat[i][i] = str[i];
            int j = i + 1;
            for (; j < n; ++j) {
                mat[i][j] = str[j];
                mat[j][i] = str[j];
                if (!m.count(string(mat[j].begin(), mat[j].begin() + i + 1))) break;
            }
            if (j == n) helper(i + 1, n, mat, m, res);
        }
    }
};
*/
