//grandyang hash table, priority queue, naive approach
//shaun read and understand
//runtime 1792ms, faster than 5%, mem less than 14%
/*
实现一个简单的搜索自动补全系统，我们用谷歌或者百度进行搜索时，会有这样的体验，输入些单词，搜索框会弹出一些以你输入为开头的一些完整的句子供你选择，这就是一种搜索自动补全系统。根据题目的要求，补全的句子是按之前出现的频率排列的，高频率的出现在最上面，如果频率相同，就按字母顺序来显示。输入规则是每次输入一个字符，然后返回自动补全的句子，如果遇到井字符，表示完整句子结束。那么我们肯定需要一个哈希map，建立句子和其出现频率的映射，还需要一个字符串data，用来保存之前输入过的字符。在构造函数中，给了我们一些句子，和其出现的次数，那么我们就直接将其加入哈希map，然后data初始化为空字符串。在input函数中，我们首先判读输入字符是否为井字符，如果是的话，那么表明当前的data字符串已经是一个完整的句子，在哈希表中次数加1，并且data清空，返回空集。否则的话我们将当前字符加入data字符串中，现在就要找出包含data前缀的前三高频句子了，我们使用优先队列来做，设计的思路是，始终用优先队列保存频率最高的三个句子，那么我们就应该把频率低的或者是字母顺序大的放在队首，以便随时可以移出队列，所以应该是个最小堆，队列里放句子和其出现频率的pair，并且根据其频率大小进行排序，所以我们要重写优先队列的comparator。然后我们遍历哈希表中的所有句子，我们首先要验证当前data字符串是否是其前缀，没啥好的方法，就逐个字符比较，用标识符matched，初始化为true，如果发现不匹配，则matched标记为false，并break掉。然后判断如果matched为true的话，说明data字符串是前缀，那么就把这个pair加入优先队列中，如果此时队列中的元素大于三个，那把队首元素移除，因为我们设计的是最小堆，所以频率小的句子会被先移除。然后就是将优先队列的元素加到结果res中，由于先出队列的是频率小的句子，所以要加到结果res的末尾


*/
class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); ++i) {
            freq[sentences[i]] += times[i]; 
        }
        data = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            ++freq[data];
            data = "";
            return {};
        }
        data.push_back(c);
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > q(cmp);
        for (auto f : freq) {
            //key is f.first
            bool matched = true;
            for (int i = 0; i < data.size(); ++i) {
                if (data[i] != f.first[i]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                q.push(f); //minHeap
                if (q.size() > 3) q.pop(); //only keep top 3
            }
        }
        vector<string> res(q.size());
        for (int i = q.size() - 1; i >= 0; --i) {
            res[i] = q.top().first; q.pop();
        }
        return res;
    }
    
private:
    unordered_map<string, int> freq;
    string data;
};


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
