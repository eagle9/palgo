//lt discuss O(n) bucket counting and accumulate count idea, shaun absorbed
//runtime 20ms, faster than 86%, mem less than 100%
class Solution {
public:
    //O(n) with auxiliary space O(n)
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        int freqs[2000] = {0};

        //word freq, min and max frequencies
        int fmin = 0, fmax = 0;

        //loop thru the array of words, calc freq of each word and save freq of word in the index
        for (string word : words) {
            int wf = f(word);
            if (wf > fmax) fmax = wf;
            //if (wf < fmin) fmin = wf;
            freqs[wf]++;
        }

        //cumulative update of frequencies, freqs[i] stores total number of words >i
        for (int i = fmax-1; i >= 0; i--)
            freqs[i] = freqs[i] + freqs[i + 1];

        //result array
        vector<int> res(queries.size());

        //loop thru queries
        for (int i = 0; i < queries.size(); i++) {
            //calc freq of query
            int qf = f(queries[i]);
            //if freq exceeds the max frequencies in words, continue , skip it will be zero in result
            if (qf >= fmax) continue;

            //otherwose, save in result the next freq [counts] from frequencies after "query frequency"
            //O(1)
            res[i] = freqs[qf + 1];
        }

        return res;
    }


    //frequency func to calc least character freq in word
    int f(string word) {
        if (word.empty())
            return 0;

        int arr[26] = {0}; //store freq for each char
        for (char c : word) {
            arr[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0)
                return arr[i];
        }

        return 0;
    }

};
