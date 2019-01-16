758. Bold Words in String
Easy
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.
Topic: String
Hint: First, determine which letters are bold and store that information in mask[i] = if i-th character is bold. Then, insert the tags at the beginning and end of groups. The start of a group is if and only if (mask[i] and (i == 0 or not mask[i-1])), and the end of a group is similar.