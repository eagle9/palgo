//hua monotonic descreasing stack
//runtime 288ms, faster than 97%, mem less than 100%
class StockSpanner {
public:
  StockSpanner() {}
 
  int next(int price) {
    int span = 1;
      //bigger fish
    while (!stk.empty() && price >= stk.top().first) {
      span += stk.top().second;  
      stk.pop();
    }
    //price < top or stk.empty
    stk.emplace(price, span);
    return span;
  }
private:
  stack<pair<int, int>> stk; // {price, span}, ordered by price DESC.
};
/**
 * 
