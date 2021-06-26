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
 */
 //jz cpp, beats 33%
class AnagramMapper : public Mapper
{
  public:
    void Map(Input<string> *input)
    {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, string& value);
        while (!input->done())
        {
            vector<string> words = split(input->value(), " ");
            for (string word : words)
            {
                string tmp = word;
                sort(tmp.begin(), tmp.end());
                output(tmp, word);
            }
            input->next();
        }
    }

    vector<string> split(const string &str, string delim)
    {
        vector<string> results;
        int lastIndex = 0, index;
        while ((index = str.find(delim, lastIndex)) != string::npos)
        {
            results.push_back(str.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.length();
        }
        if (lastIndex != str.length())
        {
            results.push_back(str.substr(lastIndex, str.length() - lastIndex));
        }
        return results;
    }
};

class AnagramReducer : public Reducer
{
  public:
    void Reduce(string &key, Input<string> *input)
    {
        // Write your code here
        // Please directly use func 'output' to output
        // the results into output buffer.
        // void output(string &key, vector<string>& value);
        vector<string> results;
        while (!input->done())
        {
            results.push_back(input->value());
            input->next();
        }
        output(key, results);
    }
};
