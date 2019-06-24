/*

lai idea basic calculator idea, apply higher level to * /, boom, accepted
tokenizer number, + - * /, space
1.compute the parenthesis level of each operator
2.use a stack to main the execution order of operators
  a. if top operator < current, push
  b. if top operator > current, pop
3.use a separate stack to main operands
  a. when we scan an operand, push
  b. when we pop an operator, pop two operands and push the result
shaun implemented this idea, clean idea and natural thinking, 
tokenizer,  numbers and ops, clear dealing with parenthesis

runtime 20ms, faster than 40%, mem less than 79%

test with example to ensure the dealing with parenthesis is correct
  */
class Solution {
private:
    stack<int> numbers;
    stack<pair<int,char>> ops; //level and op
    void evalTop() {
        int right = numbers.top(); numbers.pop();
        int left = numbers.top(); numbers.pop();
        char op = ops.top().second; 
        ops.pop(); //bug 1, should not miss this pop!!!
        switch (op) {
            case '+': numbers.push(left + right); break;
            case '-': numbers.push(left - right); break;
            case '*': numbers.push(left * right); break;
            case '/': numbers.push(left / right); break;
        }
    }
public:
    int calculate(string s) {
        //int res = 0, sign = 1, n = s.size();
        int n = s.size();
        int level = 0; //parenthesis level
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0') {
                int num = 0;
                while (i < n && s[i] >= '0') {
                    num = 10 * num + (s[i++] - '0');
                }
                //res += sign * num;
                --i; //key point, very smart
                numbers.push(num);
            } 
           
            
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                int level = (c == '+' || c == '-' )? 0 : 1;
                //same level, eval from left to right
                //if top.level >= current level, eval top
                while (!ops.empty() && ops.top().first >= level) {
                    evalTop();
                }
                //now top.level < current level
                ops.push(make_pair(level,c));
                //ops.emplace(level,c); //works too
            }
        }
        while (!ops.empty()) {
            evalTop();
        }
        return numbers.top();
    }
};
