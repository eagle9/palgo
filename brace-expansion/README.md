1087. Brace Expansion
Medium 130 15 Favorite Share

A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.

Example 1:
Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]

Example 2:
Input: "abcd"
Output: ["abcd"]

Note:

1 <= S.length <= 50
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.
Accepted 10.5K
Submissions 17.2K

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Google | 6

Decode String Medium
Letter Case Permutation Easy
Brace Expansion II Hard

All generated strings are of the same size. How can we generate all of these strings?
Do a backtracking on which each level of it has to choose one single (e.g. 'a') character or any character of the given parenthesized group (e.g. "{a,b,c}")
