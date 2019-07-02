/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
//grandyang dfs idea, all 1-cells are connected, so natural dfs. cutting is use of direction variable and sync with robot direction
//runtime 20ms, faster than 49%, mem less than 43%
class Solution {
public:
    
    /////////               left    down       right    up
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        dfs(robot, 0, 0, 0, visited);
    }
    void dfs(Robot& robot, int x, int y, int dir, unordered_set<string>& visited) {
        robot.clean();
        visited.insert(to_string(x) + "-" + to_string(y));
        for (int i = 0; i < 4; ++i) {
            int cur = (i + dir) % 4, newX = x + dirs[cur][0], newY = y + dirs[cur][1];
            if (!visited.count(to_string(newX) + "-" + to_string(newY)) && robot.move()) {
                dfs(robot, newX, newY, cur, visited);
                
                //let the robot go back to previous position and direction before dfs call
                // hard part, not easy to come up
                //[>] --------> [>]
                //              [<]
                //[<] <---------[<]
                //[>]
                //turnLeft first or turnRight first does not matter
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                
            }
            //sync robot direction and direction variable i and direction delta 
            //why turnRight not turnLeft?  actually does not matter 
            robot.turnRight();
            //robot.turnLeft();  okay too
        }
    }
};

/*
这道题就是经典的扫地机器人的题目了，之前经常在地里看到这道题，终于被LeetCode收录了进来了，也总算是找到了一个好的归宿了。回归题目，给了我们一个扫地机器人，给了4个API函数可供我们调用，具体实现不用我们操心，让我们实现打扫房间cleanRoom函数。给的例子中有房间和起始位置的信息，但是代码中却没有，摆明是不想让我们被分心。想想也是，难道我们在给扫地机器人编程时，还必须要知道用户的房间信息么？当然不能够啦，题目中也说了让我们盲目Blindfolded一些，所以就盲目的写吧。既然是扫地，那么肯定要记录哪些位置已经扫过了，所以肯定要记录位置信息，由于不知道全局位置，那么只能用相对位置信息了。初始时就是(0, 0)，然后上下左右加1减1即可。位置信息就放在一个HashSet中就可以了，同时为了方便，还可以将二维坐标编码成一个字符串。我们采用递归DFS来做，初始化位置为(0, 0)，然后建一个上下左右的方向数组，使用一个变量dir来从中取数。在递归函数中，我们首先对起始位置调用clean函数，因为题目中说了起始位置是能到达的，即是为1的地方。然后就要把起始位置加入visited。然后我们循环四次，因为有四个方向，由于递归函数传进来的dir是上一次转到的方向，那么此时我们dir加上i，为了防止越界，对4取余，就是我们新的方向了，然后算出新的位置坐标newX和newY。此时先要判断visited不含有这个新位置，即新位置没有访问过，还要调用move函数来确定新位置是否可以到达，若这两个条件都满足的话，我们就对新位置调用递归函数。注意递归函数调用完成后，我们要回到调用之前的状态，因为这里的robot是带了引用号的，是全局通用的，所以要回到之前的状态。回到之前的状态很简单，因为这里的机器人的运作方式是先转到要前进的方向，才能前进。那么我们后退的方法就是，旋转180度，前进一步，再转回到原来的方向。同理，我们在按顺序试上->右->下->左的时候，每次机器人要向右转一下，因为move函数只能探测前方是否能到达，所以我们必须让机器人转到正确的方向，才能正确的调用move函数。如果用过扫地机器人的童鞋应该会有影响，当前方有障碍物的时候，机器人圆盘会先转个方向，然后再继续前进，这里要实现的机制也是类似的，参见代码如下：*/
