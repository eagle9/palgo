//jz student li, runtime 9ms, faster than 14%
/*
Unionfind:
这是一个有向图问题

先考虑有没有环:

如果图有环, 那么又有两种情况:

要么是没有任何一个点有两个parent, 这种情况下我们就得删除形成环的那个边
5 <- 1 -> 2
     ^    | 
     |    v
     3 <- 4
要么就是有一个点有两个parent, 这种情况下我们也是要删除形成环的那个边. 在这里要注意一下,
因为我们的程序默认是先删除有两个parent的那个点的后面的一条边, 所以在这种情况下我们要返回另一条边,
例如在这个例子中我们会先删除(5 -> 1)这条边, 但这个是错误的, 我们应该删除(3 -> 1)这条边, 这个会在程序里处理
5 -> 1 -> 2
     ^    | 
     |    v
     3 <- 4
图没有环, 那么肯定是有一个点有两个parent, 删掉一个即可

      1
     /  \
    v    v
   2 ---> 3



*/
class UnionFind {
  int[] father;

  public UnionFind(int n){
    this.father = new int[n];
    
    for(int i = 0; i < n; i++){
      father[i] = i;
    }
  }
  
  public int find(int a){
    if(father[a] == a){
      return a;
    }
    
    father[a] = find(father[a]);
    return father[a];
  }
  
  public void union(int a, int b){
    int fa = find(a);
    int fb = find(b);
    
    if(fa != fb){
      father[fa] = fb;
    }
  }
}

public class Solution {
    /*
     * @param edges: List[List[int]]
     * @return: return List[int]
     */
    public int[] findRedundantDirectedConnection(int[][] edges) {
        // write your code here
        if(edges == null || edges.length == 0 ||
          edges[0] == null || edges.length == 0){
            return null;
          }
        
        Set<Integer> points = new HashSet<>();
        Map<Integer, Integer> parent = new HashMap<>();
        List<int[]> candidates = new ArrayList<>();
        
        for(int[] edge : edges){
          int src = edge[0];
          int dst = edge[1];
          
          points.add(src);
          points.add(dst);
          if(parent.get(dst) == null){
            parent.put(dst, src);
            continue;
          }
          
          candidates.add(new int[]{parent.get(dst), dst});
          candidates.add(new int[]{src, dst});
          
          //删除这个有两个father的边
          edge[1] = 0;
        }
          
        UnionFind uf = new UnionFind(points.size());
        for(int[] edge : edges){
          if(edge[1] == 0){
            continue;
          }
          
          int src = edge[0] - 1;
          int dst = edge[1] - 1;
          //有环
          if(uf.find(src) == uf.find(dst)){
            //所有点只有一个father
            if(candidates.isEmpty()){
              return edge;
            }
            //有点有两个father, 而且删掉一个边以后发现
            //还是有环, 这时候我们应该删除第二个边
            return candidates.get(0);
          }
          
          uf.union(src, dst);
        }
        
        //没有环, 那么证明我们之前删除的那个边是对的
        return candidates.get(1);
    }
}
