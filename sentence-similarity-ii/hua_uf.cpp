//hua union find with string elements, shaun understood and think it is better than
//ufset with int
//runtime 272ms, faster than 81%
//adding ranks_ does not help, shaun tried this
//most case start ufset without rank, add it at last or just quick mention
class UnionFindSet {
public:
    bool Union(const string& word1, const string& word2) {
        const string& p1 = Find(word1, true);
        const string& p2 = Find(word2, true);
        if (p1 == p2) return false;  
        /*
        //shaun added rank, slower
        if (ranks_[p1] < ranks_[p2]) {
            parents_[p1] = p2;
        }else if (ranks_[p2] < ranks_[p1]) {
            parents_[p2] = p1;
        }else { //same rank
            parents_[p1] = p2;
            ranks_[p2]++;
        }*/
        
        parents_[p1] = p2; 
        return true;
    }
    
    //Find can add new element on the fly
    const string& Find(const string& word, bool create = false) {
        //added code to deal with word that's not in uf set yet
        if (!parents_.count(word)) {
            if (!create) return word;
            //ranks_[word] = 0; //shaun added
            return parents_[word] = word;
        }
        
        /*
        string w = word;
        while (w != parents_[w]) {
            parents_[w] = parents_[parents_[w]];
            w = parents_[w];
        }
        return parents_[w];
        */
        //shaun modified
        if (word != parents_[word]) {
            parents_[word] = Find(parents_[word]);
        }
        return parents_[word];
        
        
    }
private:
    unordered_map<string, string> parents_;
    //unordered_map<string, int> ranks_;
};
 
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        UnionFindSet s;
        //Union function adds new elements too
        for (const auto& pair : pairs)
            s.Union(pair.first, pair.second);
        
        for (int i = 0; i < words1.size(); ++i) 
            if (s.Find(words1[i]) != s.Find(words2[i])) return false;
        
        return true;
    }
};
