//jz linhuchong, beats 77.20%
class DataStream {
    private ListNode head, tail;
    private Map<Integer, ListNode> numToPrev;
    private Set<Integer> duplicates; 
    
    public DataStream() {
        // dummy
        head = new ListNode(0);
        tail = head;
        
        numToPrev = new HashMap<>();
        duplicates = new HashSet<>();
    }
    
    private void remove(int number) {
        ListNode prev = numToPrev.get(number);
        prev.next = prev.next.next;
        numToPrev.remove(number);
        
        // change tail and prev of next
        if (prev.next != null) {
            numToPrev.put(prev.next.val, prev);
        } else {
            tail = prev;
        }
    }
    
    public void add(int number) {
        if (duplicates.contains(number)) {
            return;
        }
        
        if (numToPrev.containsKey(number)) {
            remove(number);
            duplicates.add(number);
        } else {
            ListNode node = new ListNode(number);
            numToPrev.put(number, tail);
            tail.next = node;
            tail = node;
        }
    }
    
    public int firstUnique() {
        if (head.next != null) {
            return head.next.val;
        }
        return -1;
    } 
}
