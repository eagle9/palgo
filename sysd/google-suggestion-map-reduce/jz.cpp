/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
class TopTenFrequentWordsMapper: public Mapper {
public:
    void Map(string prefix, Input<Document>* input) {
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, int value);
        
        while (!input->done()) {
            vector<string> words = splitString(input->value().content);
            for (string &word : words) {
                if (word.size() >= prefix.size() && word.substr(0, prefix.size()) == prefix) {
                    output(word, 1);
                }
            }
            input->next();
        }
    }
private:
    vector<string> splitString(string doc) {
        vector<string> words;
        stringstream ss(doc);
        string word;
        while (getline(ss, word, ' ')) {
            if (word.empty()) {
                continue;
            }
            words.push_back(word);
        }
        return words;
    }
};


class TopTenFrequentWordsReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        int count = 0;
        while (!input->done()) {
            count += input->value();
            input->next();
        }
        // insert if it is a valid candidate
        if (minHeap.size() < k || (!minHeap.empty() && minHeap.top().count < count)) {
            minHeap.push(DataType(key, count));
        }
        // remove least frequent word if size too large
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    void cleanUp() {
        // Please directly use func 'output' to output 
        // the top k pairs <word, times> into output buffer.
        // void output(string &key, int &value);
        
        vector<DataType> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        
        for (int i = res.size() - 1; i >= 0; i--) {
            output(res[i].word, res[i].count);
        }
    }
private:
    // top 10 most common words contain prefix
    int k = 10;
    
    class DataType {
    public:
        string word;
        int count;
        DataType(string word, int count) {
            this->word = word;
            this->count = count;
        }
        
        bool operator<(const DataType &other) const {
            if (count != other.count) {
                return count > other.count;
            }
            return word < other.word;
        }
    };
    
    // minHeap to get top k
    priority_queue<DataType> minHeap;
};
