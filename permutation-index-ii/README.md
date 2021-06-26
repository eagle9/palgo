198. Permutation Index II
Description
Given a permutation which may contain repeated numbers, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.

Example
Given the permutation [1, 4, 2, 2], return 3.
not yet fully understand the idea

i from tail to 0   
i = 3, A[i] = 2,  map[2] = 1
count = 0
j from 4 to 3
index = 1
fact = 4-3 = 1

i = 2, A[i] = 2, map[2] = 2, multiFact *= map[2] ---> 2
count = 0
j from 3 to 3
  j = 3, A[2] == A[3] 
index = 1
fact = 4 - 2 = 2

i = 1, A[i] = 4, map[4] = 1
count=0
j from 2 to 3
   j = 2, A[1] A[2] = 4 > 2, count=1
   j = 3, A[1] A[3] = 4 > 2, count=2
index += 2 * 2/2 = 3
fact *= 3-1 --- 4

i = 0, A[i]= 1, map[1] = 1
count=0
j from 1 to 3
  j = 1, A[0] A[1] --- 1 < 4
  j = 2, A[0] A[2] ----1 < 2
  j = 3, A[0] A[3] --- 1 < 2
index = 3
fact *= 3 - 0 ---- 4*3 = 12


