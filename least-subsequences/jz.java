
//jz idea, shaun understood and commented, beats 87%
/*
keep track of the tail elements in all subsequences of strictly descending order

use a custom object to store not only the value of tail, but also the index of tail element
if list of tails is empty - add the current element into list of tail element (new sub sequence)
else, compare the new element with all tails - if the new element fits an existing subsequences (base on tail value) - update tail
if the new element does not fit in existing subsequences - add a new one (by adding a new tail)
At the end return the length of tail list - which will be the number of subsequences.
It should be O(Nk) time and O(k) space, N being the number of elements, k is the number of subsequences in final anwser
*/
//key is to come up the tail class and rule to update the tail list
public class Solution {
    class Tail {
        int index;
        int value;
        public Tail (int i, int v) {
            index = i;
            value = v;
        }
    }
    
    public int LeastSubsequences(List<Integer> arrayIn) {
        if (arrayIn.size() <=1) {
            return arrayIn.size();
        }    

        List<Tail> tails = new ArrayList<>();
        for (int i = 0; i < arrayIn.size(); i++) {
            int current = arrayIn.get(i);
            
            if (tails.size() == 0) {
                tails.add(new Tail(i, current));
            }
            else {
                boolean newSubsequence = true;
                //test if i,current can be tail of any existing tails
                for (Tail t : tails) {
                    if (current < t.value && i > t.index) {
                        // update tail of a subsequence
                        t.value = current;
                        t.index = i;
                        newSubsequence = false;
                        break;
                    }
                }
                //i,current can not fit into any existing tails
                if (newSubsequence) {
                    tails.add(new Tail(i, current));
                }
            }
        }
        return tails.size();
    }
}
