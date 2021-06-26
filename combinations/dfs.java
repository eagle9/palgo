/*
--------------------- 
作者：flowercha 
原文：https://blog.csdn.net/u010500263/article/details/18435495 
/*classical approach, shaun digested, draw the recusion tree, beats 30%
//n = 4, k = 2
//recursion tree
//          
     1     2       3         4
 /  | \  /  \    /
 2  3  4 3  4   4
*/         
public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        //combination list
        List<List<Integer>> cList = new ArrayList<>();
        List<Integer> comb = new ArrayList<>();
        
        if(n<k) return cList;
        helper(n, k, cList, comb, 1);
        return cList;
    }
    
     //n and k are needed, 
    //cList to store all combinations
    //comb is the iterating candidate
    //for first number in comb, we can start with 1, then next number will be 2 or above
    //draw the recusion tree:1

    public void helper(int n, int k, List<List<Integer>> cList, List<Integer> comb, int start){
        // one possible combinition constructured
        if(comb.size() == k){
            //keypoint: get a copy of candidate comb, comb will be updated during entire recursion call tree 
            cList.add(new ArrayList<Integer> (comb));
            return;
        }
        
        else{
            //for each level of recursion, try all possibilities
            for(int i=start; i<=n; i++){// try each possibility number in current position
                comb.add(i);
                helper(n, k, cList, comb, i+1); // after selecting number for current position, process next position
                comb.remove(comb.size()-1); // clear the current position to try next possible number, backtracking, easy to see from the recusion tree
            }
        }
    }
}

