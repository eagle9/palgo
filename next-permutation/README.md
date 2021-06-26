31. Next Permutation
Medium 1877 588 Favorite Share

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Companies: Facebook | 30 Google | 11 Sumologic | 8 Microsoft | 5 Amazon | 3 Uber | 3 Quora | 3 Houzz | 2 Adobe | 2 Rubrik | 2 Apple | 2

Similar:
Permutations Medium
Permutations II Medium
Permutation Sequence Medium
Palindrome Permutation II Medium

Topic: Array
idea forming, clean idea, or change direction to form new clean idea
or adjust raw idea for clean, clean and correct
this problem, idea generation is really hard!
you can use examples, typical examples, while problem itself might not give you such example. 
you have to create you own. use longer

brute force
i know how to generate permutation, P(n,n)
vector<string> res
sort res
but brute force can not satisfy no extra storage use requirement

find input vi -> string
return next string, if last, return first
not clean, 
try a new idea: 
1,2,3   from right to left, first number is 3, second is 2 
1 a b
how we make this larger? assume unique numbers input list
if b > a, swap ab

132
 look 32, 2 is smaller, no swap
 look 13, 3>1, swap, 312, but 3 is larger than 2, so swap 12, get 231 
123
132   find the largest idx, and number before it is 1, next rank is 2
   largest goes to 0, next2 goes bf1, bf1 goes to max, max goes to 0
213
  largest 3 at 0, bf1, swap  231
231
  max3 at 1, bf2, 2next is 3, swap 23,    
312
321
get rank for each number, 3 -> 3, 2->2,1->1 

kind of clumsy and no clear rule is derived. 
improve or new idea---> let me take a break
1,2,7,4,3,1   <--- from n-2, while >=, ++i 
1,2,7,4,3,1   //find 2, candidate for 1+ 
  -
1,2,7,4,3,1  //from n-1,find 3 just 1+ of 2, 
  -     -
1,3,7,4,2,1  //swap 2 and it's 1+ , and make ____ part smallest
    -------

1,2,7,3,4,1  
      - -
1,2,7,4,3,1
	    ---
1,2,7,4,1,3

1,2,3,4  ---- special case, no up slodpe going <-, i start from n-1
    - -
1,2,4,3    works too

 4,3,2,1  --- spacial case 2, 
-         can not find 4--, i=-1, no candidate for 1+, directly reverse all 
 1,2,3,4       
