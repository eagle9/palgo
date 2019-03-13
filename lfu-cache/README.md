460. LFU Cache
Hard
60%
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 4 Bloomberg | 4 LinkedIn | 2 Snapchat | 2 Microsoft | 2 Adobe | 2 Uber | 2 

Similar:
LRU Cache Hard
Design In-Memory File System Hard

Topic: Design

idea: my initial design pseudo code, it is hard, critical to keep cache, freq, and count consistent. a lot of details 
yet to implement 
use 3 HashMaps, for count, use sorted_map or TreeMap 
Map<Integer,Integer> freq  key to its count
help us to find key with min freq
TreeMap<Integer,Set<Pair> count     count -> list of Pair(key, ts)  whose count is freq
   set<Pair> sorted by ts ascending order, that means least recently( early)  in the beginning 
Map<Integer,Integer> cache to store key value pairs
capacity
//requirement O(1) time
public void put(k, v) {
	if (cache.containsKey(k)) return; //clarify update freq????
	//new key 
	if (cache.size() == capacity) {
		//evict least freq item
		//find the key with min freq
		Integer min = count.firstKey();
		Set<Integer> keys = cout.get(min);
		int keyx = keys.iterator.next();
		if (keys.size() > 1) {
			key1 ... keyk ties being the min 
			//find the least recently used keyx
			
		}
		//just one key keyx with the min freq
		cache.remove(keyx);
		int n = freq.get(keyx);
		freq.remove(keyx);
		//update count too
		Set<Pair> set = count.get(n);
		
			
	}
	//now less than capacity
	cache.put(k,v);
	freq.put(k, 1);
	Set<Integer> cur = count.getOrDefault(1,new HashSet<>());
	cur.add(k);

}

public int get(int k) {
	if (cache.containsKey(k)) {
		//increment freq for k
		int n = freq.get(k);
		freq.put(k, n+1);
		Set<Integer> prev = count.get(n);
		Set<Integer> cur = count.get(n+1);
		prev.remove(k); //k freq no longer n
		cur.add(k); //k freq now n+1
		return cache.get(k);
	}else {
		return -1;
	}
}

shaun idea after LRU-cache
combine linked_list<pair<int,int>> , map<int,int>, map<int,list<>::iterator
like hua's approach
logn to O(1) with cacheNode
it is indeed a very hard problem 
