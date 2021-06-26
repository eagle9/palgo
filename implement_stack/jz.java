//jiuzhang python --> java
//Your submission beats 49.20% Submissions! down from 80% in python

public class Stack {
    // initialize your data structure here.
    private List<Integer> list = new ArrayList<>();

    // @param x, an integer, push a new item into the stack
    // @return void
    public void push(int x) {
        list.add(x);
    }

    // @return void, pop the top of the stack
    public void pop() {
        //move all elements before last element from list head
        //then add to the end of list
        //then last in element will be at the head of the list
        /*
        for (int i = 0; i < list.size() - 1; i++) {
            list.add(list.remove(0));
        }
        list.remove(0);
        */
        int n = list.size();
        if (n > 0) {
            list.remove(n-1);
        }
    }

    //@return an integer, return the top of the stack
    public int top() {
        
        Integer top = null;
        for (int i = 0; i < list.size(); i++) {
            top = list.remove(0);
            list.add(top);
        }
        return top;
        
        /*
        Integer top = null;
        int n = list.size();
        if (n > 0)
            top = list.get(n-1);
        return top;
        */
    }

    //@return an boolean, check the stack is empty or not.
    public boolean isEmpty() {
        return list.size() == 0;
    }
}
