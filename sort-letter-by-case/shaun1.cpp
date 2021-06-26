//shaun's own idea and code, similar to what I learned from sort colors
//verify correctness with a test case
//accepted first sub, beats 60%, 
#include <stdio.h>
#include <ctype.h>
class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars) {
        
        int n = chars.size();
        int i = 0, j = n-1, k = 0;
        while (k < j) {
            //if (chars[k] >= 'a' && chars[k] <= 'z') {
            if (islower(chars[k])) {
                swap(chars[i], chars[k]);
                i++;
                k++;
            }else {
                swap(chars[j], chars[k]);
                j--;
            }
            
        }
    }
};
