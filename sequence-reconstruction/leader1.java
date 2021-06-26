//lint leader1, runtime 34ms, faster than 83%, not understand
class Solution {
    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        int n = org.length;
        int[] pos = new int[n + 1];
        for(int i = 0; i < n; i++){
            pos[org[i]] = i;
        }
        int totalMatch = n - 1;
        boolean[] matched = new boolean[n + 1];
        boolean noEmpty = false;
        for(int i = 0; i < seqs.size(); i++){
            int size = seqs.get(i).size();
            if(size > 0){
                noEmpty = true;
            }
            for(int j = 0; j < size; j++){
                if(seqs.get(i).get(j) < 1 || seqs.get(i).get(j) > n){
                    return false;
                }
                if(j == 0){
                    continue;
                }
                int pre = seqs.get(i).get(j-1), cur = seqs.get(i).get(j);
                if(pos[pre] >= pos[cur]){
                    return false;
                }
                //not quite to understand
                if(matched[cur] == false && pos[pre] + 1 == pos[cur]){
                    totalMatch--;
                    matched[cur] = true;
                }
            }
        }
        //not understand
        return (totalMatch == 0 && noEmpty) || (!noEmpty && n == 0);
    }
}

/*
lint signature
public class Solution {
    
     //@param org: a permutation of the integers from 1 to n
     //@param seqs: a list of sequences
     //@return: true if it can be reconstructed only one or false
    
    public boolean sequenceReconstruction(int[] org, int[][] seqs) {
        // write your code here
        int n = org.length;
        int[] pos = new int[n + 1];
        for(int i = 0; i < n; i++){
            pos[org[i]] = i;
        }
        int totalMatch = n - 1;
        boolean[] matched = new boolean[n + 1];
        boolean noEmpty = false;
        for(int i = 0; i < seqs.length; i++){
            int size = seqs[i].length;
            if(size > 0){
                noEmpty = true;
            }
            for(int j = 0; j < size; j++){
                if(seqs[i][j] < 1 || seqs[i][j] > n){
                    return false;
                }
                if(j == 0){
                    continue;
                }
                int pre = seqs[i][j - 1], cur = seqs[i][j];
                if(pos[pre] >= pos[cur]){
                    return false;
                }
                //not quite to understand
                if(matched[cur] == false && pos[pre] + 1 == pos[cur]){
                    totalMatch--;
                    matched[cur] = true;
                }
            }
        }
        //not understand
        return (totalMatch == 0 && noEmpty) || (!noEmpty && n == 0);
    }
}
*/
