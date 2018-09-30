http://www.lintcode.com/en/problem/consistent-hashing/
generally speaking a distributed database using horizontal sharking is to take id mod n, where n is the number of database servers, then find data at (id mod n) server. The problem of this approach is when we need to add more servers, say n is increased to n+1, almost all data will need to be moved. This leads to inconsistency. In order to alleviate the problem caused by the naïve hash (% n), a new hash function is introduced: consistent hashing. There are many implemenatios of this algorithm. Let’s implement a simple consistent hashing here. 
1.  Id % 360, assume there are 3 machines at the beginning, let the 3 machines taking care of 0~119, 120~239, 240~ 359 respectively. Check h = id % 360 and which range is h located, then go the corresponding machine.  
2.  When the number of machines increased from n to n+1, find the largest range from the n ranges, break it into two equal size ranges, move half of its data to (n+1)th machine. 
3.  For example, when the number of machine increased from 3 to 4, find the 3rd range 0 ~ 119 which is the largest, break 0~119 into 0~59 and 60~119.  0~59 still goes to the first machine, 60~119 goes to the 4th machine.
4.  When the number of machine increased from 4 to 5, find the 3rd range 120~239 which is the largest, break it into two equal ranges – 120~179 and 180~239
Assume at the beginning all data is stored at one single machine, when the number of machines is increased to n,  what’s the ranges and corresponding machines? 
Assume n <=360. When there are multiple ranges being the largest, we break the largest range with the smaller id.  For example, 0~119 and 120~239 have the same size, but the first range corresponds to machine id 1, the second range corresponds to machine id 2, so we break 0~119. 
If the maximal interval is [x, y], and it belongs to machine id z, when you add a new machine with id n, you should divide [x, y, z] into two intervals:
[x, (x + y) / 2, z] and [(x + y) / 2 + 1, y, n]
Example 
for n = 1, return
1.  [
2.    [0,359,1]
3.  ]
represent 0~359 belongs to machine 1.
for n = 2, return
1.  [
2.    [0,179,1],
3.    [180,359,2]
4.  ]
for n = 3, return
1.  [
2.    [0,89,1]
3.    [90,179,3],
4.    [180,359,2]
5.  ]
for n = 4, return
1.  [
2.    [0,89,1],
3.    [90,179,3],
4.    [180,269,2],
5.    [270,359,4]
6.  ]
for n = 5, return
1.  [
2.    [0,44,1],
3.    [45,89,5],
4.    [90,179,3],
5.    [180,269,2],
6.    [270,359,4]
7.  ]
https://blog.csdn.net/jmspan/article/details/51740066?utm_source=copy

