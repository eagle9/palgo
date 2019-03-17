/*
ling huchong
use HashMap 
Store all words' prefix into a HashMap. The HashMap's value = is it a prefix or a word
if a prefix it is false, if it is a word it is true.
Runtime: 47 ms, faster than 40.75% of Java online submissions for Word Search II.
*/
public class Solution {
    public static int[] dx = {0, 1, -1, 0};
    public static int[] dy = {1, 0, 0, -1};
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    public List<String> findWords(char[][] board, String[] words) {
        if (board == null || board.length == 0) {
            return new ArrayList<>();
        }
        if (board[0] == null || board[0].length == 0) {
            return new ArrayList<>();
        }
       	
	    //grid visited 2d array, control dfs backtracking	
        boolean[][] visited = new boolean[board.length][board[0].length];
		//all pref -> pure pref or word
        Map<String, Boolean> prefixIsWord = getPrefixSet(words);
		//store result in set first, to prevent repeated word found, at last convert to list
        Set<String> wordSet = new HashSet<>();
		//idea start for each ij of the grid, start grid dfs using pref map
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                visited[i][j] = true;
                dfs(board, visited, i, j, String.valueOf(board[i][j]), prefixIsWord, wordSet);
                visited[i][j] = false;
            }
        }
        
        return new ArrayList<String>(wordSet);
    }
   	//for all words, get all possible pref 0 to wordlen-2, pref ->true
	//  word->true 
	//  iterate all words, for each word, iterate all its pref
    private Map<String, Boolean> getPrefixSet(String[] words) {
        Map<String, Boolean> prefixIsWord = new HashMap<>();
        for (String word : words) {
            for (int i = 0; i < word.length() - 1; i++) {
                String prefix = word.substring(0, i + 1);
                if (!prefixIsWord.containsKey(prefix)) {
                    prefixIsWord.put(prefix, false);
                }
            }
            prefixIsWord.put(word, true);
        }
        
        return prefixIsWord;
    }
    
    private void dfs(char[][] board,
                     boolean[][] visited,
                     int x,
                     int y,
                     String word,
                     Map<String, Boolean> prefixIsWord,
                     Set<String> wordSet) {
			//changing para: word longer and longer
        if (!prefixIsWord.containsKey(word)) {
            return;
        }
        
        if (prefixIsWord.get(word)) {
            wordSet.add(word);//use set to prevent repeated found 
        }
        
        for (int i = 0; i < 4; i++) {
            int adjX = x + dx[i];
            int adjY = y + dy[i];
            
            if (!inside(board, adjX, adjY) || visited[adjX][adjY]) {
                continue;
            }
            
            visited[adjX][adjY] = true;
			//recur word+1
            dfs(board, visited, adjX, adjY, word + board[adjX][adjY], prefixIsWord, wordSet);
            visited[adjX][adjY] = false; //backtrack
        }
    }
    
    private boolean inside(char[][] board, int x, int y) {
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }
}

