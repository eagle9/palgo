//grandyang idea, shaun java code, beats 77%
//key point, prevent i j out of bound
class Solution {
    public boolean validWordSquare(List<String> words) {
        if (words == null || words.size() == 0) return false;
        int ROWS = words.size();
        
        if (ROWS != words.get(0).length()) return false;
        
        for (int i = 0; i < ROWS; i++) {
            int COLS = words.get(i).length();
            for (int j = 0; j < COLS; j++ ) {
                //i already < ROWS
                if (j >= ROWS) return false;
                
                //i is index of charAt words.get(j)
                //j is already < words.get(i).length
                if (i >= words.get(j).length()) return false;
                //the above two tests are preventing the following statement to be out bound
                if (words.get(i).charAt(j) != words.get(j).charAt(i)) return false;
            }
            
        }
        //passed all tests
        return true;
    }
}
