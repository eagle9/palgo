//shaun code from hua's stack idea
//runtime 276ms, faster than 97%, mem less than 100%
class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        int span=1;
        bool flag = false;
        while (!st.empty() && price >= st.top().first) {
            auto p = st.top(); st.pop();
            span += p.second;
        }
        st.emplace(price,span);
        return span;
    }
private:
    stack<pair<int, int>> st; //pair price and span
    //tried store price and index, does not work, 
    //key to draw stack push pop sequence with an example
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
