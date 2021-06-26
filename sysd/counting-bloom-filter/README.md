555. Counting Bloom Filter
Difficulty: Medium

http://www.lintcode.com/en/problem/counting-bloom-filter/

Implement a counting bloom filter. Support the following method:

add(string). Add a string into bloom filter.
contains(string). Check a string whether exists in bloom filter.
remove(string). Remove a string from bloom filter.
Example

CountingBloomFilter(3) 
add("lint")
add("code")
contains("lint") // return true
remove("lint")
contains("lint") // return false
