//shaun came up very close to grandyang idea, puzzled when asked to do inplace change.
//key insight is that when you move i from 0 to len-1, changeIndex will lag i, so there is no interferences
// a loop for i to go from 0 to len-1, another loop and pointer to go through all repeating chars, then update with changeIndex/storeIndex
//runtime 8ms, faster than 88%, mem less than 99%
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), changeIndex = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && chars[j] == chars[i]) ++j;
            //out of while loop, now i to j-1 all same char
            //len = j-1 -i + 1 = j - i
            chars[changeIndex++] = chars[i];
            if (j - i > 1) {
                for (char c : to_string(j - i)) chars[changeIndex++] = c;
            }
            i = j;
        }
        return changeIndex;
    }
};

//shaun own first try, getting close, confused when changing in place
class Solution1 {
public:
    int compress(vector<char>& chars) {
        int len = 0;
        /*   
        test with example
        0 1 2 3 4
        a a b b b
        i= 0, j = 0, j =1
        len = 1 + 1 = 2   a2
        i = 2, j = 2, j = 4
        len = 1 + 1
        b 
        b
        b
        After you are done modifying the input array in-place, return the new length of the array.
        Could you solve it using only O(1) extra space?
        */
        int i = 0, n = chars.size();
        
        while (i < n) {
            int j = i;
            while  (j+1 < n && chars[j] == chars[j+1]) {
                j++;
            }
            //now i to j-1 all equal chars
            //compress
            if (i == j) { //chars[i] no reps following
                len++;
                
            }else {
                for(char c: to_string(j-i) ) {
                    chars[i+1];
                }
            }
            i = j+1;
            
        }
        return len;
        
    }
};
