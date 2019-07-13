// Forward declaration of the knows API.
//shaun own idea, accepted second sub
//runtime 84ms, faster than 32%, mem less than 20%
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        for (int i = 0; i <= n-1; ++i) {
            //count --how many knows i?
            //count2 -- i knows how many, should be just himself
            int count = 1, count2 = 1;
            for (int j = 0; j <= n-1; ++j) {
                if (i == j) continue;
                if (knows(i,j)) count2++;
                if (count2 > 1) break; //early break since count2 should remain 1
                if (knows(j,i)) count++;
         	}
            
            //all knows i,  and i does not knows others except self
            if (count2 == 1 && count == n) return i;
        }
        return -1;
    }
};
