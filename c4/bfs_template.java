// T stands for the storage type you want 
//neighbor stands for the nodes at next level reachable from head
//set stores nodes that have been visited
//queue stores nodes that are ready to be expanded to next level
//set and queue are good friends, any time you put a node into queue, you put it into set at the same time
Queue<T> queue = new LinkedList<>();
Set<T> set = new HashSet<>();

set.add(start);
queue.offer(start);
while (!queue.isEmpty()) {
    T head = queue.poll();
    for (T neighbor : head.neighbors) {
        if (!set.contains(neighbor)) {
            set.add(neighbor);
            queue.offer(neighbor);
        }
    }
}
