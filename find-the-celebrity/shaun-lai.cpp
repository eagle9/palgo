// Forward declaration of the knows API.
bool knows(int a, int b);

//lai O(n) idea, shaun read and understand
//test with example, correct can be proved, check comment before return candidate
//runtime 60ms, faster than 97%, mem less than 46%
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        //
        for (int i = 1; i < n; ++i) {
            //if candidate knows i, then candidate is no longer a candidate
            if (knows(candidate,i)) {
                candidate = i;
            }
        }
        //candidate does not know anybody > candidate
        //now check if candidate 
        //candidate knows no body
        //now check if all other knows candidate, and candidate knows anybody < candidate
        for (int i = 0; i < n; ++i){
            if (i == candidate) continue;
            if (!knows(i, candidate))  return -1;
            if (i < candidate && knows(candidate,i)) return -1;
        }
        
        //now candidate does not know any other
        //all other knows candidate
        return candidate;
    }
};
