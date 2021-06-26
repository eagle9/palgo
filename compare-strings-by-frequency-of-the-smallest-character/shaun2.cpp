//first try TLE
//second try with hashtable, runtime 1020ms, faster than 5%, mem less than 100%
//third try with multiset upper_bound,  runtime 40ms, faster than 40%, mem less than 100%
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        vector<int> ans(n);
        multiset<int> setf;
        for (string w: words) {
            setf.insert(f(w));
        }
        for (int i = 0; i < n; ++i) {
            int fq = f(queries[i]);
            auto it = setf.upper_bound(fq); //it --- first it > f1
            ans[i] = distance(it, setf.end());
        }
        return ans;
    }
private:
    //freq of smallest char
    int f0(string word) {
        sort(word.begin(), word.end());
        int i = 0;
        
        while (i+1 < word.size() && word[i] == word[i+1]) i++;
        //now i != i+1, w[i+1] new char
        //   i  i+1
        //aa a  b
        return i+1; 
    }
    int f(string word) {
        if (word.empty())
            return 0;

        int arr[26] = {0}; //store freq for each char
        for (char c : word) {
            arr[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) return arr[i];
        }

        return 0;
    }

};
