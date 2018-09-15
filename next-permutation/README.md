52. Next Permutation
Description
Given a list of integers, which denote a permutation.

Find the next permutation in ascending order.

The list may contains duplicate integers.

Example
For [1,3,2,3], the next permutation is [1,3,3,2]
iterate i from tail, find nums[i] that drops(>) from nums[i+1]
i = 2,nums[i] = 2
iterate j from tail, find nums[j] > nums[i], j = 3, nums[j] = 3

swap(nums,i,j) --> 1332
reverse nums from i+1 to end, why? 
1,3,2,3,1
i = 2, nums[i] = 2
j =3, nums[j] = 3
1,2,3,2,1
reverse i+1 to end, or 3 to end
1,2,3,1,2
makes sense, but not fully understand

For [4,3,2,1], the next permutation is [1,2,3,4]
from tail, find number that drops, wont find, i ended up with -1
reverse i+1 to end of nums

companies: google

related: next-permutation-ii which ask for the same thing. Instead of return next p, it changes parameter in place. same code, slightly change, tested working
