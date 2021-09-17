//https://evelynn.gitbooks.io/amazon-interview/content/chapter1/insert-delete-getrandom-o1.html
/*
for O(1) insert and remove we have to use something utilizing hashcode, like hashmap or hashset.

And for constant time getRandom, we will need something that has random access like array or arraylist.

We can combine them together, using a hashmap to store a map from value to their index in the arraylist.
*/
public class RandomizedSet {

    /** Initialize your data structure here. */
    Map<Integer, Integer> map; //value => index
    List<Integer> list;
    public RandomizedSet() {
        list = new ArrayList<>();
        map = new HashMap<>();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (map.containsKey(val)) return false;
        map.put(val, list.size());
        list.add(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (map.isEmpty() || !map.containsKey(val)) return false;
        
        //to remove index = map.get(val)
        //  move tail of list to the index, move the val to tail
        list.set(map.get(val), list.get(list.size() - 1));
        map.put(list.get(list.size() - 1), map.get(val));
        
        //remove from list
        list.remove(list.size() - 1);
        //remove from map
        map.remove(val);
        return true;
    }

    /** Get a random element from the set. */
    public int getRandom() {
        Random rand = new Random();
        int r = rand.nextInt(list.size());
        return list.get(r);
    }
}
