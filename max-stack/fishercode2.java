//fishercode idea2, beats 18%    
class Node {
      int val;
      Node prev;
      Node next;

      public Node(int val) {
        this.val = val;
      }
    }

    class DoublyLinkedList {
      Node head;
      Node tail;

      public DoublyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
      }

      public Node add(int val) {
        /**For this doubly linked list, we always add it to the end of the list*/
        Node x = new Node(val);
        x.next = tail;
        x.prev = tail.prev;
        tail.prev.next = x;
        tail.prev = tail.prev.next;
        return x;
      }

      public int pop() {
        /**for pop(), we always pop one from the tail of the doubly linked list*/
        return unlink(tail.prev).val;
      }

      public Node unlink(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        return node;
      }

      public int peek() {
        return tail.prev.val;
      }
    }

    class MaxStack {
      TreeMap<Integer, List<Node>> treeMap;
      /**
       * the reason we have a list of nodes as treemap's value is because one value could be pushed
       * multiple times into this MaxStack and we want to keep track of all of them.
       */
      DoublyLinkedList doublyLinkedList;

      /** initialize your data structure here. */
      public MaxStack() {
        treeMap = new TreeMap();
        doublyLinkedList = new DoublyLinkedList();
      }

      public void push(int x) {
        Node node = doublyLinkedList.add(x);
        if (!treeMap.containsKey(x)) {
          treeMap.put(x, new ArrayList<>());
        }
        treeMap.get(x).add(node);
      }

      public int pop() {
        int val = doublyLinkedList.pop();
        List<Node> nodes = treeMap.get(val);
        nodes.remove(nodes.size() - 1);
        if (nodes.isEmpty()) {
          treeMap.remove(val);
        }
        return val;
      }

      public int top() {
        return doublyLinkedList.peek();
      }

      public int peekMax() {
        return treeMap.lastKey();
      }

      public int popMax() {
        int max = treeMap.lastKey();
        List<Node> nodes = treeMap.get(max);
        Node node = nodes.remove(nodes.size() - 1);
        doublyLinkedList.unlink(node);
        if (nodes.isEmpty()) {
          treeMap.remove(max);
        }
        return max;
      }
    }
  

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
