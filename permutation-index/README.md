197. Permutation Index
Description
Given a permutation which contains no repeated number, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.

Example
try to understand zhengyang's:
Given [1,2,4], return 1
Given [1,4,2], return 2 
Given [4,1,2], return 5

I would rather take zhengyang's permutation index ii solution, which can deal with duplicated numbers. 
no duplication is just a case of duplication
or yuanbin's, which can be easily extended to solve ii


   for 4 at 0, 2 numbers < 4, put 1 at 0, 2!, put 2 at 0, 2!, so 2*2!  (n-1-i)!
   for 1 at 1, 0 numbers < 1, trailing number is single number,   given 41, no contribution, 0*1!
Given [4,2,1], return 6
   for 4 at 0, 2 numbers < 4, contributes 2*2! = 4
   for 2 at 1, 1 number < 2, contribute 1 * 1! = 1
   total 5 permutations before it, so index is 6

given [4,2,3,1]
   for 4 at 0, 3 numbers < 4,  3*3! = 18   
      updateMap with 4, no key is > 4 , map not updated 
   for 2 at 1, 1 numbers < 2,  1*2! = 2
      updateMap with 2, 3&4 >2, v--, map[3] = 1, map[4] = 2, 2 is taken, any larger k no longer has 2
   for 3 at 2, 1 numbers < 3,  1,2<3, but we can only use 1, 2 is taken
      so 1*1! =1
   so index = 18+2+1   + 1 = 22
4231
4312
4321
total 4! = 24, only 2 after, so it last index is 24 - 2 = 22
Okay now i understand zhengyang's
But not yet understand jz's
     
Time complexity is O(n^2), space is O(1)
You can use next permutation, but time is O(n!) 
Difficulty: medium

