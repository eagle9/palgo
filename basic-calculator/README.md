224. Basic Calculator
Hard

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Indeed | 11 Uber | 7 Facebook | 6 Microsoft | 5 Google | 4 Intuit | 3 Amazon | 3 Pocket Gems | 2 Roblox | 2 Paypal | 2

Topic: Math, Stack, Compiler
Similar: 
Evaluate Reverse Polish Notation, Medium
Basic Calculator II, Medium
Different Ways to Add Parentheses, Medium
Expression Add Operators, Hard
Basic Calculator III, Hard


lai idea
tokenizer number, +/-, (), space
1.compute the parenthesis level of each operator
2.use a stack to main the execution order of operators
  a. if top operator < current, push
  b. if top operator > current, pop
3.use a separate stack to main operands
  a. when we scan an operand, push
  b. when we pop an operator, pop two operands and push the result
