443. String Compression
Easy 386 1221 Favorite Share

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.
 
Follow up:
Could you solve it using only O(1) extra space?
 
Example 1:
Input:
["a","a","b","b","c","c","c"]
Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

Example 2:
Input:
["a"]
Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
 
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
 

Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
Accepted 57,032
Submissions 150,085

Contributor Grain_In_Ear

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Goldman Sachs | 9 Microsoft | 6 Amazon | 5 Facebook | 3 Google | 2 Apple | 2 Walmart Labs | 2 Wayfair | 2

Similar:
Count and Say Easy
Encode and Decode Strings Medium
Design Compressed String Iterator Easy

Topic: String

Hint 1:
How do you know if you are at the end of a consecutive group of characters?
