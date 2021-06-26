//shaun off gy idea 1, use hash table to track chars in secret
//runtime 4ms, faster than 94%, mem less than 15%
class Solution {
public:
    string getHint(string secret, string guess) {
            //int m[256];
            vector<int> m(256,0); //count of each char in secret
            int bulls = 0, cows = 0;
            for (int i = 0; i < secret.size(); ++i) {
                if (secret[i] == guess[i]) ++bulls;
                else ++m[secret[i]];
            }
            for (int i = 0; i < secret.size(); ++i) {
                //guess position not right, but guessed number is in, by def, it is cow
                if (secret[i] != guess[i] && m[guess[i]] > 0) {
                    ++cows;
                    --m[guess[i]];
                }
            }
            return to_string(bulls) + "A" + to_string(cows) + "B";
        }
    
};
