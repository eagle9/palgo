//Your submission beats 99.60% Submissions!
public class Solution {
    public int[] nextPermutation(int[] num) {
        if (num == null) {
            return num;
        }
        
        int len = num.length;
        
        // Find the index which drop.
        int dropIndex = -1;
        for (int i = len - 1; i >= 0; i--) {
            if (i != len - 1 && num[i] < num[i + 1]) {
                dropIndex = i;
                break;
            }
        }
        
        // replace the drop index.
        if (dropIndex != -1) {
            for (int i = len - 1; i >= 0; i--) {
                if (num[i] > num[dropIndex]) {
                    swap(num, dropIndex, i);
                    break;
                }
            }    
        }
        
        // reverse the link.
        int l = dropIndex + 1;
        int r = len - 1;        
        while (l < r) {
            swap(num, l, r);
            l++;
            r--;
        }
        return num;
    }
    
    public void swap(int[] num, int l, int r) {
        int tmp = num[l];
        num[l] = num[r];
        num[r] = tmp;
    }
    
}
