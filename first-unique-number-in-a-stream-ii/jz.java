//jz linhuchong, beats 77.20%
//some of the details are not easy to understand or get right
//numToPrev is pretty hard 
class DataStream {
    private ListNode head, tail; //head stores unique numbers
    private Map<Integer, ListNode> numToPrev; //given a number, find its prev node
    private Set<Integer> duplicates;  //set of duplicated numbers
    
    public DataStream() {
        // dummy
        head = new ListNode(0);
        tail = head;
        
        numToPrev = new HashMap<>();
        duplicates = new HashSet<>();
    }
    
    private void remove(int number) {
        
        //  prev -> (number,next) -> prev.next.next
        ListNode prev = numToPrev.get(number);
        prev.next = prev.next.next;
        numToPrev.remove(number);
        
        // change tail and prev of next
        if (prev.next != null) {
            numToPrev.put(prev.next.val, prev); //why? 
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
