class Solution {
    class Point {
        int x,y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        public boolean equals(Point p) {
            return x == p.x && y == p.y;
        }
        //equal object should have same hashcode
        //the following design does not work when work with set<Point>
        public int hashCode() {
            return x*y+y;
        }
    }
    //runtime 911ms, faster than 2%
    public int minAreaRect(int[][] points) {
        Set<String> set = new HashSet<>();
        //Set<Point> set = new HashSet<>();
        for (int [] p: points) {
            //set.add(new Point(p[0],p[1]));
            set.add(p[0] + "," + p[1]);
        }
        int N = points.length;
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            int [] p1 = points[i];
            for (int j = i+1; j < N; j++) {
                // p1       p2
                // p3        p4
                int [] p4 = points[j];
                if ( p4[0] == p1[0] || p4[1] == p1[1]) continue; //p1 and p4 parallel to x or y axis
                //Point p2 = new Point(p1[0],p4[1]);
                //Point p3 = new Point(p4[0],p1[1]);
                String p2 = p1[0] + "," + p4[1];
                String p3 = p4[0] + "," + p1[1];
                if (set.contains(p2) && set.contains(p3)) {
                    res = Math.min(res, Math.abs(p1[0] - p4[0]) * Math.abs(p1[1] - p4[1]));
                }
                
            }
            
        }
        if (res == Integer.MAX_VALUE) return 0;
        else return res;
    }
}

/*
最原始的想法就是，我们找出和坐标轴平行的三个点，来确定第四个点。这么做的话，时间复杂度是O(N^3)，果然超时了。这说明我对4sum理解还不够深刻啊！两天前刚做过的454. 4Sum II，做法就是确定两个数字的和，然后看剩余的两个数字的和是否存在即可。也就是说4sum的时间复杂度只有O(N^2)。

这个题正确的做法是先确定对角线两个点！题目要求所有的边必须平行坐标轴，就是告诉我们只用确定对角线两个元素，剩余的两个点可以直接求出来即可！因此不需要确定3个点的O(N^3)的遍历。

所以啊，还是需要活学活用才行啊！

时间复杂度是O(N^2)，空间复杂度是O(N)。

class Solution(object):
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points = map(tuple, points)
        points.sort()
        pset = set(points)
        N = len(points)
        res = float('inf')
        for i in range(N - 1):
            p1 = points[i]
            for j in range(i + 1, N):
                p4 = points[j]
                if p4[0] == p1[0] or p4[1] == p1[1]:
                    continue
                p2 = (p1[0], p4[1])
                p3 = (p4[0], p1[1])
                if p2 in pset and p3 in pset:
                    res = min(res, abs(p3[0] - p1[0]) * abs(p2[1] - p1[1]))
        return res if res != float("inf") else 0
--------------------- 
作者：负雪明烛 
来源：CSDN 
原文：https://blog.csdn.net/fuxuemingzhu/article/details/83961509 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
