20. Valid Parentheses
Easy 3034 148 Favorite Share

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 29 Facebook | 22 Microsoft | 13 Google | 9 Apple | 9 Twitter | 7 Bloomberg | 6 LinkedIn | 4 Blizzard | 3 Adobe | 3 VMware | 3 Uber | 3 Walmart Labs | 3 Spotify | 3 Atlassian | 2 Tencent | 2 Yahoo | 2 GoDaddy | 2 Oracle | 2 Cisco | 2 More

Similar:
Generate Parentheses Medium
Longest Valid Parentheses Hard
Remove Invalid Parentheses Hard
Check If Word Is Valid After Substitutions Medium

An interesting property about a valid parenthesis expression is that a sub-expression of a valid expression should also be a valid expression. (Not every sub-expression) e.g.
{ { } [ ] [ [ [ ] ] ] } is VALID expression
          [ [ [ ] ] ]    is VALID sub-expression
  { } [ ]                is VALID sub-expression
Can we exploit this recursive structure somehow?
What if whenever we encounter a matching pair of parenthesis in the expression, we simply remove it from the expression? This would keep on shortening the expression. e.g.
{ { ( { } ) } }
      |_|

{ { (      ) } }
    |______|

{ {          } }
  |__________|

{                }
|________________|

VALID EXPRESSION!
The stack data structure can come in handy here in representing this recursive structure of the problem. We can't really process this from the inside out because we don't have an idea about the overall structure. But, the stack can help us process this recursively i.e. from outside to inwards.
