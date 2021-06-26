//grandyang lt discuss runtime 285ms, faster than 40%, not fully understand yet
class Solution {
    public List<int[]> getSkyline(int[][] buildings) {
        //before java10, generics parameter type must be reference type, so int[] is okay
        //first time i see this
        List<int[]> height = new ArrayList<>();
        List<int[]> res = new ArrayList<>();
        
        for (int[] a : buildings) {
            //a0 a1 a2 --- left, right, height
            //这里为了区分左右边界，将左边界的高度存为负数，建立左边界和负高度的pair，再建立右边界和高度的pair，
            //height.add(new int[]{a[0], -a[2]});
            int [] p1 = {a[0],-a[2]};
            height.add(p1);
            height.add(new int[]{a[1], a[2]});
        }
        //给height按照左边界排序，这样我们就可以按顺序来处理那些关键的节点了
        /*
        Collections.sort(height, (a, b) -> {
            if(a[0] != b[0]) 
                return a[0] - b[0];
            return a[1] - b[1];
        });
        */
        Collections.sort(height, new Comparator<int[]>() {
            public int compare(int [] a, int [] b) {
                if (a[0] != b[0]) return a[0]- b[0];
                return a[1]-b[1];
            }
        });
        /*
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return b.intValue() - a.intValue();
            }
        });
        */
        //max heap with java8 lambda, type inferenced
        //PriorityQueue<Integer> pq = new PriorityQueue<>( (a,b) -> {return b-a;});
        PriorityQueue<Integer> pq = new PriorityQueue<>( (a,b) -> b-a);
        //要在heap中放入一个0，这样在某个没有和其他建筑重叠的右边界上，我们就可以将封闭点存入结果res中
        pq.offer(0);
        /*
        按顺序遍历这些关键节点，如果遇到高度为负值的pair，说明是左边界，那么将正高度加入heap中，然后取出此时集合中最高的高度，即最后一个数字，然后看是否跟pre相同，这里的pre是上一个状态的高度，初始化为0，所以第一个左边界的高度绝对不为0，所以肯定会存入结果res中。接下来如果碰到了一个更高的楼的左边界的话，新高度存入multiset的话会排在最后面，那么此时cur取来也跟pre不同，可以将新的左边界点加入结果res。第三个点遇到绿色建筑的左边界点时，由于其高度低于红色的楼，所以cur取出来还是红色楼的高度，跟pre相同，直接跳过。下面遇到红色楼的右边界，此时我们首先将红色楼的高度从multiset中删除，那么此时cur取出的绿色楼的高度就是最高啦，跟pre不同，则可以将红楼的右边界横坐标和绿楼的高度组成pair加到结果res中，这样就成功的找到我们需要的拐点啦，后面都是这样类似的情况。当某个右边界点没有跟任何楼重叠的话，删掉当前的高度，那么multiset中就只剩0了，所以跟当前的右边界横坐标组成pair就是封闭点啦
        */
        int prev = 0;
        for(int[] h:height) {
            if(h[1] < 0) {
                pq.offer(-h[1]);
            } else {
                pq.remove(h[1]);
            }
            int cur = pq.peek();
            if(prev != cur) {
                res.add(new int[]{h[0], cur});
                prev = cur;
            }
        }
        return res;
    }
}
